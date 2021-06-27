#include <iostream>
#include <queue>
#include<stack>

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

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    
    if(root == NULL){
        return;
    }
    stack<BinaryTreeNode<int> *> s1_l_r;
    stack<BinaryTreeNode<int> *> s2_r_l; 
    
    s1_l_r.push(root);
    
    while(s1_l_r.size() != 0 || s2_r_l.size() !=0){
        if(s2_r_l.size() == 0){
            while(s1_l_r.size() !=0){
                cout<< s1_l_r.top()->data << " ";
                if(s1_l_r.top()->left != NULL){
                    s2_r_l.push(s1_l_r.top()->left);
                }
            	if(s1_l_r.top()->right != NULL){
                    s2_r_l.push(s1_l_r.top()->right);
                }
            	s1_l_r.pop();
            }
            cout<<endl;
        }else if (s1_l_r.size() == 0){
            while(s2_r_l.size() != 0){
                cout<<s2_r_l.top()->data<<" ";
                if(s2_r_l.top()->right != NULL){
                    s1_l_r.push(s2_r_l.top()->right);
                }
            	if(s2_r_l.top()->left != NULL){
                    s1_l_r.push(s2_r_l.top()->left);
                }
            	s2_r_l.pop();
            }
            cout<<endl;

        }
    }
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
    zigZagOrder(root);
}
