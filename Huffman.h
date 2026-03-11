#include <string>
#include <queue>
#include <fstream>
#include "Node.h"
#include <unordered_map>
#include <iostream>

using namespace std;

#ifndef HUFFMAN_H
#define HUFFMAN_H
/**
 * @class Huffman
 * @brief Provides methods to compress and decompress files using Huffman coding.
 *
 * Typical flow:
 * 1) countFreq() to count characters,
 * 2) buildTree() to build the Huffman tree,
 * 3) makeCodes() to get codes,
 * 4) createHead()/readHead() to write/read the header,
 * 5) compress()/decompress() to process files.
 */

class Huffman {
private:
    /**
        * @brief Root of the Huffman tree. nullptr means no tree yet.
        */
    Node* root=nullptr;
    /**
        * @brief Recursively delete the whole Huffman tree.
        * @param node Pointer to the current node to delete.
        */
    void deleteTree(Node* node);
    /**
     * @brief Count how many times each byte appears in a file.
     * @param path Path of the input file to read (binary).
     * @param freqMap Map from character -> frequency (output).
     */

    void countFreq(const std::string& path,std::unordered_map< char,int>& freqMap);
    /**
     * @brief Build a Huffman tree from a frequency map.
     * @param freqMap Map from character -> frequency.
     * @return Pointer to the root node of the built tree (or nullptr if empty).
     */

    Node* buildTree(const std::unordered_map<char, int>& freqMap);
    /**
     * @brief Create Huffman codes for each leaf by walking the tree.
     * @param node Current node in the tree.
     * @param code The bit-string built so far ('0' for left, '1' for right).
     * @param codes Output map from character -> its Huffman code.
     */

    void makeCodes(Node* node,std::string code,std::unordered_map<char,std::string>& codes);

    /**
     * @brief Create a header string that stores total count and per-char frequencies.
     * @param freqMap Map from character -> frequency.
     * @return Header text (multiple lines) to write into the output.
     */

    string createHead(const std::unordered_map<char, int>& freqMap);
    /**
    * @brief Read a header string and rebuild the frequency map.
    * @param header The header text read from the compressed file.
    * @param freqMap Output map from character -> frequency reconstructed from the header.
    */

    void readHead (const std::string& header, std::unordered_map<char, int>& freqMap);
    /**
    * @brief Compare two nodes for sorting (by weight, then by letter).
    * @param a First node.
    * @param b Second node.
    * @return true if a should come before b in ascending order.
    */

    static bool CompareAndTieBreak(Node* a, Node* b);

public:
    /**
    * @brief Construct a new Huffman object. Starts with no tree.
    */
    Huffman();
    /**
     * @brief Destroy the Huffman object. Frees the tree.
     */
    ~Huffman();

    /**
     * @brief Compress a file using Huffman coding.
     * @param inPath Path to the input file (to read, binary).
     * @param outPath Path to the output file (to write, binary). Header + bits are written.
     */
    void compress(const std::string& inPath, const std::string& outPath);

    /**
     * @brief Decompress a Huffman-compressed file.
     * @param inPath Path to the compressed input file (with header).
     * @param outPath Path to the decompressed output file (binary).
     */
    void decompress(const std::string& inPath, const std::string& outPath);
};

#endif //HUFFMAN_H

