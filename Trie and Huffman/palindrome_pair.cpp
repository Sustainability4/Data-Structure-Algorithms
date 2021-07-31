#include<vector>
#include <bits/stdc++.h>
using namespace std;
class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;
    int childCount;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
        childCount = 0;
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

    bool add(TrieNode *root, string word) {
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
            root->childCount++;
        }

        // Recursive call
        return add(child, word.substr(1));
    }

    void add(string word) {
        if (add(root, word)) {
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
    
    string reverse(string input, string output){
        if(input.size() == 0){
            return output;
        }
        output = reverse(input.substr(1),output);
        return output+input[0];
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

    /*..................... Palindrome Pair................... */

    bool isPalindromePair(vector<string> words) {
        // Write your code here
        for(int i = 0 ; i<words.size(); i++){
            vector<string> output;
            print_subs(words[i],output);
            for(int j = 0; j<output.size(); j++){
                add(output[i]);
            }
        }
        
        for(int i = 0 ; i<words.size(); i++){
            string output;
            output = reverse(words[i],output);
            if(search(root,output)){
                return true;
            }
        }
        
        return false;
        
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;
    vector<string> words(n);

    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }

    cout << (t.isPalindromePair(words) ? "true" : "false");
}
