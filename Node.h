#ifndef NODE_H
#define NODE_H


struct Node {

    Node(char letter, int weight) {
        this->letter = letter;
        this->weight = weight;
        this->zero = nullptr;
        this->one = nullptr;
        this->code = "";

    }

    Node(char letter, int weight, Node *zero, Node *one) {
        this->letter = letter;
        this->weight = weight;
        this->zero = zero;
        this->one = one;
        this->code = "";
    }

    char letter;        // letter character to be stored
    Node* zero;
    Node* one;
    int weight;         // count for how many times the character is used in the file
    std::string code;   // binary string code created from the huffman tree
};


#endif //NODE_H


#ifndef COMPARE_WEIGHTS
#define COMPARE_WEIGHTS
/**
 * Class needed for the to compare Nodes in the priority queue
 * @see https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/
 */
struct compareWeights{
    bool operator()(Node* const& lhs, Node* const& rhs) const {
        // If weights are different, the one with the larger weight has lower priority.
        if (lhs->weight != rhs->weight) {
            return lhs->weight > rhs->weight;
        }
        // If weights are the same, the one with the larger character value has lower priority.
        // This acts as the tie-breaker.
        return lhs->letter > rhs->letter;
    }
};
#endif // COMPARE_WEIGHTS


