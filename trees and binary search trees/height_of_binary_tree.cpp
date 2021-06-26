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
    if(root == NULL){
        return 0;
    }

    return 1 + max(height(root->left)+height(root->right));
}

pair<int,int> heightDiameter(BinaryTreeNode<int>*root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;

        return p;
    }

    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;

    int rd = rightAns.second;
    int rh = rightAns.first;

    pair<int,int> hd;
    hd.first = 1+max(lh,rh);
    hd.second = max(max(ld,rd),(lh+rh));

    return hd;
}
int diameter(BinaryTreeNode<int> * root){
    if(root == NULL){
        return 0;
    }

    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);

    return max(option1,option2,option3);
}

int height(BinaryTreeNode<int>* root) {
    // Write our code here
    if(root == NULL){
        return 0;
    }
    
    int h = 1;
    
    int h1 = height(root->left);
    int h2 = height(root->right);
    
    if(h1>h2){
        return h+h1;
    }else if(h2>h1){
        return h2+h;
    }else{
        return h1+h;
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
    cout << height(root);
}
