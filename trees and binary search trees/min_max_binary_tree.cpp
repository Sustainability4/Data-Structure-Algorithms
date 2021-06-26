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
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root->left == NULL && root->right == NULL){
        pair<int,int> p ;
        p.first =root->data;
        p.second =root->data;
        
        return p;
    }
    
    if(root->left == NULL){
        pair<int,int> right = getMinAndMax(root->right);
        
        int min_num = min(right.first,root->data);
        int max_num = max(right.second,root->data);
    
    	pair<int,int> p ;
    
    	p.first = min_num;
    	p.second = max_num;
    
    	return p; 
    }
    
    if(root->right == NULL){
        
        pair<int,int> left = getMinAndMax(root->left);
        
        int min_num = min(left.first,root->data);
        int max_num = max(left.second,root->data);
    
    	pair<int,int> p ;
    
    	p.first = min_num;
    	p.second = max_num;
    
    	return p;
        
    }
    
    
    pair<int,int> left = getMinAndMax(root->left);
    pair<int,int> right = getMinAndMax(root->right);
    
    int min_num = min(min(left.first,right.first),root->data);
    int max_num = max(max(left.second,right.second),root->data);
    
    pair<int,int> p ;
    
    p.first = min_num;
    p.second = max_num;
    
    return p; 
    
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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}
