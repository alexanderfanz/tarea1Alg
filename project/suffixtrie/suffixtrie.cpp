#include "suffixtrie.h"

Suffix_Trie::Suffix_Trie(){
	root = new Node();
}

Suffix_Trie::~Suffix_Trie(){
	delete root;
}