#include <iostream>
using namespace std;
#include<queue>

template<typename T>
class BinaryNodeTree{
    public:
    T data;
    BinaryTreeNode*left;
    BinaryNodeTree*right;

    BinaryNodeTree(T data){
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryNodeTree(){
        delete left;
        delete right;
    }
};

void printTree(BinaryNodeTree<int> * root){
    if(root == NULL){
        return;
    }


    cout<<root->data<<":";
    if(root->left != NULL){
        cout<<"L" <<" " << root->left->data<<",";
    }

    if(root->right != NULL){
        cout<<"R" <<" " << root->right->data;
    }

    cout<< endl;

    printTree(root->left);
    printTree(root->right);
}

BinaryNodeTree<int>* takeInput(){
    cout<<"Enter Data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryNodeTree<int>* root = new BinaryNodeTree<int>* (rootData);
    BinaryNodeTree<int>* leftChild = takeInput();
    BinaryNodeTree<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    
    return root;

}

BinaryNodeTree<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root data"<<endl;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryNodeTree<int>* root = new BinaryNodeTree<int>(rootData);
    queue<BinaryNodeTree<int>*> pendingNodes;
    pendingNodes.push(root);
    while(pendingNodes != 0){
        BinaryNodeTree<int>*front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter left Child of"<<front->data<<endl;
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BinaryNodeTree<int>* child = new BinaryNodeTree<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }

        cout<<"Enter roght Child of"<<front->data<<endl;
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BinaryNodeTree<int>* child = new BinaryNodeTree<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }

}
int main() {
    cout<<"Hello World!";
    BinaryNodeTree<int> * root = new BinaryNodeTree<int> (1);
    BinaryNodeTree<int> * node1 = new BinaryNodeTree<int> (2);
    BinaryNodeTree<int> * node2 = new BinaryNodeTree<int> (3);

    root->left = node1;
    root->right = node2;
}
