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
/*#include <vector>
#include<algorithm>
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
    if(root == NULL){
        return NULL;
    }
    
    if(root->data == data){
        vector<int>*Output = new vector<int>();
        Output->push_back(root->data);
        return Output;
    }
    vector<int>*leftOutput = getPath(root->left,data);;
    
    if(leftOutput !=  NULL){
            leftOutput->push_back(root->data);
            return leftOutput;
        }
    
   
    vector<int>*rightOutput = getPath(root->right,data);
    
    
    if(rightOutput != NULL){
            rightOutput->push_back(root->data);
            return rightOutput;
    }else{
            return NULL;
        }
}

int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    
    vector<int>* path_1 = getPath(root,val1);
    vector<int>* path_2 = getPath(root,val2);
    
    
    if(path_1->size() == 0 || path_2->size() == 0){
        return -1; 
    }else{
        int a = -1;
        for(int i = 0 ; i<path_1->size(); i++){
            int j = 0;
            for(int j = 0; j<path_2->size(); j++){
                if(path_1[i] == path_2[j]){
                    if(a == -1){
                        a = i;
                    }
                    
                    break;
                }
            }
        }
        //cout<<a<<endl;
        int b = path_1.at(a);
        return b;
        
    }
    
    
    
    
}*/


int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root==NULL)
        return -1;
    
    if(root->data==val1 || root->data==val2)
        return root->data;
    
    int ans1;
    int ans2;
    
    if(root->data < val1)
        ans1 = getLCA(root->right,val1,val2);
    else
        ans1 = getLCA(root->left,val1,val2);
    
    if(root->data < val2 && ans1==-1)
        ans2 = getLCA(root->right,val1,val2);
    else
        ans2 = getLCA(root->left,val1,val2);
    
    if(ans1!=-1 && ans2!=-1)
        return root->data;
    else if(ans1!=-1)
        return ans1;
    else if(ans2!=-1)
        return ans2;
    else
        return -1;
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
