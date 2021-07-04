#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/

#include<iostream> 

pair<Node<int>*,Node<int>*> constructLL(BinaryTreeNode<int>*root){
    

    if(root->right == NULL && root->left == NULL){
        std :: pair<Node<int>*,Node<int>*> p;
        Node<int>* data = new Node<int>(root->data);
        p.first = data;
        p.second = data;
        
        return p; 
    }
    std :: pair<Node<int>*,Node<int>*> p_l;
    std :: pair<Node<int>*,Node<int>*> p_r;
    
    if(root->left != NULL){
        p_l= constructLL(root->left);
        Node<int>* data = new Node<int>(root->data);
    	p_l.second->next = data;
    	p_l.second = p_l.second->next;
    }else{
        Node<int>* data = new Node<int>(root->data);
        p_l.first = data;
        p_l.second = data;
    }
    

    if(root->right != NULL){
        p_r= constructLL(root->right);
    	p_l.second->next = p_r.first;
    }else{
        p_r.first = NULL;
        p_r.second = p_l.second;
    }
    
    
    std :: pair<Node<int>*,Node<int>*> p;
    p.first = p_l.first;
    p.second = p_r.second;
    
    return p;
    
    
    
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root == NULL){
        return NULL; 
    }
    
    std :: pair<Node<int>*, Node<int>*>p = constructLL(root);
    
    return p.first;   
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
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
