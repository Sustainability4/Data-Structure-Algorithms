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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

using namespace std;

/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
	
***********************************************************/
#include<cmath>
#include<limits>
int height(BinaryTreeNode<int> * root){
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left),height(root->right));
}

bool isBSTHelp(BinaryTreeNode<int> *root, int min = -999999, int max = 99999999){
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

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
    
    if(root == NULL){
        return 0; 
    }
    if(isBST(root)){
        return height(root);
    }
    int height_left = largestBSTSubtree(root->left);
    int height_right = largestBSTSubtree(root->right);
    
    return max(height_left,height_right);
    
    
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
    cout << largestBSTSubtree(root);
    delete root;
}
