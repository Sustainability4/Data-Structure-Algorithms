#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    int count;

    Trie() {
        this->count = 0;
        root = new TrieNode('\0');
    }

    bool insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            if (!root->isTerminal) {
                root->isTerminal = true;
                return true;
            } else {
                return false;
            }
        }

        // Small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        return insertWord(child, word.substr(1));
    }

    void insertWord(string word) {
        if (insertWord(root, word)) {
            this->count++;
        }
    }
    
	void print_subs( string input, vector<string>& output){
  		if (input.size() == 0){
    		return;
  		}
        output.push_back(input);
  		print_subs(input.substr(1), output);
	}
    
    bool search(TrieNode*root,string pattern){
        if(pattern.size()==0){
            return true;
        }
        
        int index = pattern[0] - 'a';
        TrieNode *child;    
        
        if(root->children[index] == NULL){
            return false;
        }else{
            child = root->children[index];
            return search(child,pattern.substr(1));
        }
        
    }

    bool patternMatching(vector<string> vect, string pattern) {
        // Write your code here
        for(int i = 0 ; i< vect.size(); i++){
            vector<string> output;
            print_subs(vect[i],output);
            for(int i = 0; i<output.size(); i++){
                insertWord(output[i]);
            }
            //insertWord(vect[i]); 
        }
        
        return search(root, pattern);
        
        
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    string pattern;
    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }
    cin >> pattern;

    cout << (t.patternMatching(vect, pattern) ? "true" : "false");
}
