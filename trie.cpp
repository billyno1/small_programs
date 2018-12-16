#include <iostream>
#include <string>
#include <unordered_map>
#include <assert.h>

using namespace std;
class Node{
	public:
	unordered_map<char, Node*> nodeMap;
	bool isCompleteWord;
	Node(){
	    isCompleteWord = false;
		nodeMap = {};
	}
};

class Trie {
	public:
	Node * root;
	Trie() {
		root = new Node();
	}

	void insert(string str) {
		if (str.empty()) return;
		insert (root, str);
	}
	void insert(Node * root, string str) {
		unordered_map<char, Node*>::const_iterator got = (root->nodeMap).find (str[0]);
		if(got == (root->nodeMap).end()) { // char has not inserted yet
			(root->nodeMap)[str[0]] = new Node();
		}	
		if(str.size() == 1) {
			(root->nodeMap)[str[0]]->isCompleteWord = true;
		} else {
			insert((root->nodeMap)[str[0]], str.substr(1));
		}
	}

	bool isValidWord(Node *root, string str) {
		unordered_map<char, Node*>::const_iterator got = (root->nodeMap).find (str[0]);
		if(got == (root->nodeMap).end()) { // char has not inserted yet
			return false;
		} else {
			if(str.size() == 1) {
				return (root->nodeMap)[str[0]] ->isCompleteWord;
			} else {
				return isValidWord((root->nodeMap)[str[0]], str.substr(1));
			}			
		}
	}
	bool isValidWord(string str) {
		if(str.empty()) return true;
		return isValidWord(root, str);
	}
};


int main() {
	Trie trie;
	trie.insert("abc");
	trie.insert("abd");
	trie.insert("xyz");
	assert(trie.isValidWord("abc"));
	assert(trie.isValidWord("abd"));
	assert(trie.isValidWord("xyz"));
	assert(!trie.isValidWord("abe"));
	assert(!trie.isValidWord("a"));
	assert(trie.isValidWord(""));
	assert(!trie.isValidWord("abcd"));
	cout << "ALL SET"<<endl;
}	





