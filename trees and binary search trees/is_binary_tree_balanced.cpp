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

int height(BinaryTreeNode<int> * root){
    if (root == NULL){
        return 0;
    }
    
    return 1 + max(height(root->left),height(root->right));
}
pair<int,bool> isBalancedHelper(BinaryTreeNode<int> * root){
    if(root == NULL){
        pair<int,bool> p;
        p.first = 0;
        p.second = true;
        return p;
    }
    
    pair<int,bool> left = isBalancedHelper(root->left);
    pair<int,bool> right = isBalancedHelper(root->right);
    
    pair<int,bool> p;
    
    p.first = height(root);
    
    if(left.second && right.second == true){
        if(abs(left.first-right.first) <= 1){
            p.second = true;
        }else{
            p.second = false;
        }
    }else{
        p.second = false;
    }
    
    return p;
    
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    
    pair<int,bool> p = isBalancedHelper(root);
    
    return p.second;

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
    cout << (isBalanced(root) ? "true" : "false");
    int m;
}
