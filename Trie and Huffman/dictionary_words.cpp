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
    
    void print(TrieNode*root, string pattern, vector<string>& output){
        if(root->isTerminal == true){
            output.push_back(pattern);
        }
        
        for(int i = 0 ; i<26 ; i++){
            if(root->children[i]!=NULL){
                char charcter = 'a'+i;
                pattern = pattern+ charcter;
                TrieNode*child = root->children[i];
                print(child, pattern,output);
            }
        }
        
        return;
    }
    
    TrieNode* returnNode(TrieNode*root, string pattern){
        if(pattern.size()== 0){
            return root;
        }
        
        TrieNode*child;
        int index = pattern[0]-'a';
        if(root->children[index]==NULL){
            return root;
        }else{
            child = root->children[index];
            TrieNode*p = returnNode(child,pattern.substr(1));
            return p; 
        }
    }
    
    bool isthere(TrieNode*root, string pattern){
        if(pattern.size() == 0){
            return true;
        }
        
        TrieNode*child;
        int index = pattern[0]-'a';
        if(root->children[index]== NULL){
            return false;
        }else{
            child = root->children[index];
            return isthere(child, pattern.substr(1));
        }
    }

    void autoComplete(vector<string> input, string pattern) {
        // Write your code here
        for(int i = 0; i<input.size(); i++){
            insertWord(input[i]);
        }
        if(isthere(root,pattern)){
                  TrieNode*p = returnNode(root,pattern);
        		  vector<string> output;
        		  print(p,pattern,output);
        
        		  for(int i = 0 ; i<output.size(); i++){
            		  cout<<output[i]<<endl;
        		  }  
        }else{
            return;
        }

        
    }
};

int main() {
    Trie t;
    int n;
    cin >> n;

    vector<string> vect;

    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        vect.push_back(word);
    }

    string pattern;
    cin >> pattern;

    t.autoComplete(vect, pattern);
}
