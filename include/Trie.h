#include <vector>
#include <string>
#include "TrieNode.h"

using namespace std;

// trie has a root,
// methods to insert a string and get all words starting with a prefix.
class Trie {
	// a trie node
	// has 256 children, which are null if they do not exist
	TrieNode *root;

	//inserts given string into the trie
	void insertString(TrieNode *curNode, int st, string s);

	// return the last node of a walk for a given string.
	// reutrns null if the walks falls off the trie. 
	TrieNode* traverseString(TrieNode *curNode, int st, string s);

	// populates wordList with a list of all words under curNode.
	void getLeafString(TrieNode *curNode, vector<string> &wordList, string& wordRoot, string tmpSuffix);

public:
    Trie();

	void insertString(string s);

	vector<string> getWords(string s);
};
