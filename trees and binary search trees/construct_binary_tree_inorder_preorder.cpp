#include <iostream>
#include <queue>

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

using namespace std;

BinaryTreeNode<int>* buildTreeHelper(int*preorder,int*inorder,int pre_start, int pre_end, int in_start, int in_end){
    if(pre_start == pre_end){
        BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[pre_start]);
        return root;
    }
    
    if(in_start>in_end){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(preorder[pre_start]);
    
    if(in_start != in_end){
        // calculations for the left side 
        int pre_start_index_left = pre_start+1;
        int in_start_index_left = in_start;
        int i = in_start;
        while(inorder[i] != preorder[pre_start]){
            i++;
        }
        
        int in_end_index_left = i-1;
        int pre_end_index_left = pre_start_index_left + i-1-in_start_index_left;
        root->left = buildTreeHelper(preorder,inorder,pre_start_index_left,pre_end_index_left,in_start_index_left,in_end_index_left);
        
        //calculation for the right side
        int pre_start_index_right = pre_end_index_left +1;
        int pre_end_index_right = pre_end;
        
        int in_start_index_right = i+1;
        int in_end_index_right = in_end;
        
        root->right = buildTreeHelper(preorder,inorder,pre_start_index_right,pre_end_index_right,in_start_index_right,in_end_index_right);
    }
    
    
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int>* root = buildTreeHelper(preorder,inorder,0,preLength-1,0,inLength-1);
    
    return root;
    
}
BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}
