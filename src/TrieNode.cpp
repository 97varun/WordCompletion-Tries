#include "../include/TrieNode.h"

#define NULL 0

TrieNode::TrieNode() {
    isWord = false;
    for (int i = 0; i < MAX_CHAR; ++i)	this->child[i] = NULL;
}
