#include <vector>
#include <string>
#include "../include/Trie.h"

using namespace std;

// private functions

// inserts given string into the trie
void Trie::insertString(TrieNode *curNode, int st, string s) {
	// if string is exhausted, stop.
	if (st == (int) s.size()) {
		curNode->isWord = true;
		return;
	}

	// check if the appropriate link exist,
	// if it does not exist, create it.
	// if it does exist take it

	TrieNode** reqChild = &(curNode->child[(int) s[st]]);
	if (*reqChild == NULL)	*reqChild = new TrieNode();
	insertString(*reqChild, st + 1, s);
}

// return the last node of a walk for a given string.
// reutrns null if the walks falls off the trie. 
TrieNode* Trie::traverseString(TrieNode *curNode, int st, string s) {
	// if string is exhausted return current node as the end node.
	if (st == (int) s.size())	return curNode;

	// else take the corresponding link
	TrieNode** reqChild = &(curNode->child[(int) s[st]]);

	//return null if the walk fell off the trie
	if (*reqChild == NULL)	return *reqChild;

	return traverseString(*reqChild, st + 1, s);
}

// populates wordList with a list of all word under curNode.
void Trie::getLeafString(TrieNode *curNode, vector<string> &wordList, string& wordRoot, string tmpSuffix) {
	if (curNode->isWord) {
		wordList.push_back(wordRoot + tmpSuffix);
	}
	for (int i = 0; i < MAX_CHAR; ++i) {
		if (curNode->child[i] == NULL)	continue;
		getLeafString(curNode->child[i], wordList, wordRoot, tmpSuffix + (char) i);
	}
}

// public functions

Trie::Trie() {
	this->root = new TrieNode();
}

void Trie::insertString(string s) {
	insertString(this->root, 0, s);
}

vector<string> Trie::getWords(string s) {
	// traverse the trie with the given string, and finds the end node.
	TrieNode *endNode = traverseString(this->root, 0, s);


	vector<string> wordList;

	if (endNode == NULL)	return wordList;

	getLeafString(endNode, wordList, s, "");

	return wordList;
}
