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

BinaryTreeNode<int>* buildTreeHelper(int*postorder,int*inorder,int po_s, int po_e, int ino_s, int ino_e){
    if(ino_s>ino_e){
        return NULL;
    }
    
    BinaryTreeNode<int>*root = new BinaryTreeNode<int>(postorder[po_e]);
    
    // Calculation for left node
    
    int po_s_l = po_s; 
    int ino_s_l = ino_s;
    
    int i = 0;
    
    while(inorder[i]!=postorder[po_e]){
        i++;
    }
    
    int ino_e_l = i-1;
    int po_e_l = i-1-ino_s_l+po_s_l;
    
    root->left = buildTreeHelper(postorder,inorder,po_s_l,po_e_l,ino_s_l,ino_e_l);
    
    // Calculation for the right node
    int po_s_r = po_e_l +1;
    int po_e_r = po_e-1;
    
    int ino_s_r = i+1;
    int ino_e_r = ino_e;
    
    root->right = buildTreeHelper(postorder,inorder,po_s_r,po_e_r, ino_s_r,ino_e_r);
    
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    BinaryTreeNode<int>* root = buildTreeHelper(postorder,inorder,0,postLength-1,0,inLength-1);
    
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
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}
