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

int getaddress(int*array, BinaryTreeNode<int>* root, int a, int size){
    if(root == NULL){
        return 0;
    }
    
    if(root->data == a){
        array[size] = root->data;
        size = size+1;
        return size;
    }
    
    int s_l = getaddress(array, root->left, a, size);
    if(s_l == 0){
        int s_r = getaddress(array, root->right, a, size);
        if(s_r == 0){
            return 0;
        }else{
            array[s_r] = root->data;
            size = s_r+1;
            return size;
        }
    }else {
        array[s_l] = root->data;
        size = s_l+1;
        return size;
    }
    
}

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    // Write your code here
    if(root == NULL){
        return -1;
    }
    
    int array_1[1000];
    int array_2[1000];
    
    
    int size_1 = getaddress(array_1,root, a, 0);
    int size_2 = getaddress(array_2,root,b,0);
    
   
    if(size_1 == 0 || size_2 == 0){
        return -1; 
    }else{
        int a = -1;
        for(int i = 0 ; i<size_1; i++){
            int j = 0;
            for(int j = 0; j<size_2; j++){
                if(array_1[i] == array_2[j]){
                    if(a == -1){
                        a = i;
                    }
                    
                    break;
                }
            }
        }
        //cout<<a<<endl;
        return array_1[a];
        
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
    int a, b;
    cin >> a >> b;
    cout << getLCA(root, a, b);
    delete root;
}
