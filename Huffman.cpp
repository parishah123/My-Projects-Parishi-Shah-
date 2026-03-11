#include "Huffman.h"
#include "Storage/Storage.h"
#include <vector>
#include <sstream>
#include <stdexcept>

// make root empty
Huffman::Huffman() {
    root = nullptr;
}

// clean tree memory when object die
Huffman::~Huffman() {
    deleteTree(root);
}

// delete whole tree (go kids first)
void Huffman::deleteTree(Node* node) {
    if (node == nullptr) {
        return;
    }
    deleteTree(node->zero);
    deleteTree(node->one);
    delete node;
}


// count how many times each byte appears in the file
// open file in binary, read byte by byte, update map
// if file cannot open, throw error so caller knows
void Huffman::countFreq(const std::string& path, std::unordered_map<char, int>& freqMap) {
    std::ifstream inFile(path, std::ios::in | std::ios::binary);
    if (!inFile.is_open()) {
        throw std::runtime_error("Error: Could not open input file '" + path + "'.");
    }

    char c;
    while (inFile.get(c)) {
        freqMap[c]++;
    }
    inFile.close();
}

// make Huffman tree using the counts
// put all letter in small heap, small count first
// keep take 2 small one, join them make parent
// do again till only 1 left, that is root
// if file have only one kind letter, still make fake parent

Node* Huffman::buildTree(const std::unordered_map<char, int>& freqMap) {
    if (freqMap.empty()) {
        return nullptr; // no data, no tree
    }

    // min heap by weight (small first)
    std::priority_queue<Node*, std::vector<Node*>, compareWeights> pq;

    // Push all leaf
    for (auto const& pair : freqMap) {
        pq.push(new Node(pair.first, pair.second));
    }

    // only one type char is add parent so it gets code "0"
    if (pq.size() == 1) {
        Node* leaf = pq.top();
        pq.pop();
        Node* parent = new Node('\0', leaf->weight, leaf, nullptr);
        pq.push(parent);
    }

    // merge two smallest until one root left
    while (pq.size() > 1) {
        // Pop the two nodes with the lowest weights.
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new parent node. Its weight is the sum of its children.
        // The parent's character is set for tie-breaking consistency.
        int sumWeight = left->weight + right->weight;
        char parentChar;
        if (left->letter < right->letter) {
            parentChar = left->letter;
        } else {
            parentChar = right->letter;
        }
        Node* parent = new Node(parentChar, sumWeight, left, right);

        pq.push(parent);
    }

    // The last node in the queue is the root of the tree.
    if (pq.empty()) {
        return nullptr;
    } else {
        return pq.top();
    }
}


// walk in tree and give each letter code of 0 and 1
// go left add '0', go right add '1'
// if leaf node, save that code
// if only one letter, give code "0"
void Huffman::makeCodes(Node* node, std::string code, std::unordered_map<char, std::string>& codes) {
    if (node == nullptr) {
        return;
    }
// leaf: save code
    if (node->zero == nullptr && node->one == nullptr) {
        if (code.empty()) {
            codes[node->letter] = "0"; // single char file
        } else {
            codes[node->letter] = code;
        }
        return;
    }

    // go left add 0, right add 1
    makeCodes(node->zero, code + "0", codes);
    makeCodes(node->one,  code + "1", codes);
}

// make header text to store info
// write total letter count
// write how many unique letter
// then write each letter value and count
string Huffman::createHead(const std::unordered_map<char, int>& freqMap) {
    std::stringstream ss;
    long long totalCount = 0;
    for (const auto& pair : freqMap) {
        totalCount += pair.second;
    }

    ss << totalCount << '\n';
    ss << freqMap.size() << '\n';

    for (const auto& pair : freqMap) {
        ss << static_cast<int>(static_cast<unsigned char>(pair.first)) << ' ' << pair.second << '\n';
    }
    return ss.str();
}


// read header back to make frequency map again
// read total, then how many unique
// then read each letter value and freq
void Huffman::readHead(const std::string& header, std::unordered_map<char, int>& freqMap) {
    std::stringstream ss(header);
    long long totalCount;
    ss >> totalCount; // used later to stop decode

    size_t letterCount;
    ss >> letterCount;

    for (size_t i = 0; i < letterCount; ++i) {
        int charVal;
        int freq;
        ss >> charVal >> freq;
        if (ss.fail()) {
            throw std::runtime_error("Header is wrong or file is broken .");
        }
        freqMap[static_cast<char>(charVal)] = freq;
    }
}

// compress file to smaller one
// 1) count freq
// 2)make tree
// 3)make codes
// 4) write header + bits
void Huffman::compress(const std::string& inPath, const std::string& outPath) {
    // count chars
    std::unordered_map<char, int> freqMap;
    countFreq(inPath, freqMap);

    // empty input -> write empty file
    if (freqMap.empty()) {
        std::ofstream outFile(outPath, std::ios::out | std::ios::binary);
        outFile.close();
        return;
    }

    // build tree fresh
    deleteTree(root);
    root = buildTree(freqMap);

    // make code table
    std::unordered_map<char, std::string> codes;
    makeCodes(root, "", codes);

    // open storage to write bits
    Storage storage;
    if (!storage.open(outPath, "write")) {
        throw std::runtime_error("Error: Could not open output file '" + outPath + "'.");
    }

    // write header first
    std::string header = createHead(freqMap);
    storage.setHeader(header);

    // write codes for each input char
    std::ifstream inFile(inPath, std::ios::in | std::ios::binary);
    if (!inFile.is_open()) {
        storage.close();
        throw std::runtime_error("Error Could not re-open input file '" + inPath + "'.");
    }

    char c;
    while (inFile.get(c)) {
        storage.insert(codes[c]);
    }

    inFile.close();
    storage.close(); // flush last bits
}

// decompress back to normal text
// read header, make freq map
// rebuild tree
// read bits, go in tree 0=left,1=right
// when leaf found, write char
void Huffman::decompress(const std::string& inPath, const std::string& outPath) {

    // open compressed file
    Storage storage;
    if (!storage.open(inPath, "read")) {
        throw std::runtime_error("Error: Could not open compressed file '" + inPath + "'.");
    }
    Node* cur = root;
    std::string bits;

    // get header or can maybe be empty
    std::string header = storage.getHeader();
    if (header.empty()) {
        std::ofstream outFile(outPath, std::ios::out | std::ios::binary);
        outFile.close();
        storage.close();
        return;
    }

    // rebuild tree from header
    std::unordered_map<char, int> freqMap;
    long long totalCharCount;
    std::stringstream(header) >> totalCharCount;

    readHead(header, freqMap);
    deleteTree(root);
    root = buildTree(freqMap);

    // open output
    std::ofstream outFile(outPath, std::ios::out | std::ios::binary);
    if (!outFile.is_open()) {
        storage.close();
        throw std::runtime_error("Error: Could not open output file '" + outPath + "'.");
    }

    // read bits and walk tree
    Node* curr = root;
    long long decodedCount = 0;
    std::string bit_chunk;

    if (root == nullptr) {
        storage.close();
        outFile.close();
        return;
    }

    // only one kind char case
    bool isSingleCharFile = (root->one == nullptr && root->zero != nullptr && root->zero->zero == nullptr);

    while (decodedCount < totalCharCount) {
        if (isSingleCharFile) {
            // just write same char many times
            outFile.put(root->zero->letter);
            decodedCount++;
            continue;
        }

        if (!storage.extract(bit_chunk)) {
            break; // no more bits chunk
        }

        for (char bit : bit_chunk) {
            if (decodedCount >= totalCharCount) break;

            if (bit == '0') {
                cur = cur->zero;
            } else {
                cur = cur->one;
            }

            // hit leaf  output char, go back root
            if (curr->zero == nullptr && curr->one == nullptr) {
                outFile.put(curr->letter);
                decodedCount++;
                curr = root;
            }
        }
    }

    storage.close();
    outFile.close();
}