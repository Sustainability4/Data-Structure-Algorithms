#include <iostream>
#include <queue>

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
/*
#include<limits>
class IsBSTReturn {
    public: 
    bool IsBst; 
    int minimum;
    int maximum;
    
};

IsBSTReturn isBSTHelp(BinaryTreeNode<int> * root){
    if(root == NULL){
        IsBSTReturn output;
        output.IsBst = true;
        output.maximum = -19999999;
        output.minimum = 9999999; 
        
        return output;
    }
    
    IsBSTReturn right = isBSTHelp(root->right);
    IsBSTReturn left = isBSTHelp(root->left);
    
    int minimum = min(root->data, min(left.minimum,right.maximum));
    int maximum = max(root->data, max(right.maximum, left.maximum));
    bool IsBSTFinal = (root->data <= minimum) && (root->data > maximum) && right.IsBst && left.IsBst;
    
    IsBSTReturn output;
    output.IsBst = IsBSTFinal;
    output.minimum = minimum; 
    output.maximum = maximum; 
    
    return output;
}

*/

#include<limits>
#include<iostream>
#include <cstdint>
#include <climits>
using namespace std;

bool isBSTHelp(BinaryTreeNode<int> *root, int min = INT_MIN, int max = INT_MAX){
    if(root == NULL){
        return true;
    }
    
    if(root->data <min || root->data>max){
        return false;
    }
    
    bool isleftok = isBSTHelp(root->left,min,root->data-1);
    bool isrightok = isBSTHelp(root->right, root->data, max);
    
    return isleftok && isrightok;
}

bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
    
    //IsBSTReturn  output = isBSTHelp(node);
    //return output.IsBst;  
    
    bool a = isBSTHelp(root);
    
    return a;   
    
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBST(root) ? "true" : "false");
}
