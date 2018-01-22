// alphabet size
const int  MAX_CHAR = 256;

class TrieNode {
public:
    bool isWord;
    TrieNode *child[MAX_CHAR];

    TrieNode();
};