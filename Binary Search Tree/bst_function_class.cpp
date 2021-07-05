#include <iostream>
using namespace std;

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

#include<queue>

// class BST {
//     // Define the data members
//     BinaryTreeNode<int>*root;
//    public:
//     BST() { 
//         // Implement the Constructor
//         root = NULL;
//     }
    
//     ~ BST(){
//         delete root;
//     }

// 	/*----------------- Public Functions of BST -----------------*/
    
//     int minimum(BinaryTreeNode<int>* node){
//         if(node->left == NULL && node->right == NULL){
//             return node->data;
//         }else if(node->left == NULL && node->right != NULL){
//             int m = minimum(node->right);
//             return m; 
//         }else if (node->left != NULL && node->right == NULL){
//             int n = minimum(node->left);
//             return n; 
//         }else{
//             int m = minimum(node->right);
//             int n = minimum(node->left);
            
//             int p = min(node->data, min(m,n));
            
//             return p; 
//         }
//     }
    
//     BinaryTreeNode<int>* removedata(int data, BinaryTreeNode<int>*node){
//         if(node == NULL){
//             return node;
//         }
        
//         if(node->data == data){
//             if(node->left == NULL && node->right == NULL){
//                 BinaryTreeNode<int>*output = node;
//                 node = NULL;
//                 delete(output);
//             }else if(node->left == NULL && node->right != NULL){
//                 BinaryTreeNode<int>*element = node;
//                 node = node->right;
//                 delete(element);
//             }else if(node->left != NULL && node->right == NULL){
//                 BinaryTreeNode<int>*element = node;
//                 node = node->left;
//                 delete(element);
//             }else{
//                 node->data = minimum(node->right);
//             }
//         }else if(node->data < data){
//             node->right = removedata(data, node->right);
            
//         }else{
//             node->left = removedata(data,node->left);
//         }
        
//         return node;
//     }

//     void remove(int data) { 
//         // Implement the remove() function 
//         BinaryTreeNode<int>* output = removedata(data, root);
//         root = output;
        
//     }

//     void print() { 
//         // Implement the print() function
//         if (root == NULL){
//             return; 
//         }
        
//         queue<BinaryTreeNode<int>*> q;
        
//         q.push(root);
        
//         while(q.size() != 0){
//             cout<<q.front()->data<<":";
            
//             if(q.front()->left != NULL){
//                 cout<<"L"<<":"<<q.front()->left->data<<",";
//                 q.push(q.front()->left);
//             }
            
//             if(q.front()->right != NULL){
//                 cout<<"R"<<":"<<q.front()->right->data;
//                 q.push(q.front()->right);
//             }
            
//             q.pop();
//         }
//     }
    
//     BinaryTreeNode<int>* insertData(int data, BinaryTreeNode<int>*node){
//         if(root == NULL){
//             BinaryTreeNode<int>*output = new BinaryTreeNode<int>(data);
//            // node = output;
//             return output;
//         }
        
//         if(data >= node->data){
//         	node->right = insertData(data, node->right);
//         }else{
//             node->left = insertData(data,node->left);
//         }
        
//         return node;
//     }
    
//     void insert(int data) { 
//         // Implement the insert() function 
//         BinaryTreeNode<int>*node = insertData(data,root);
//         root = node;
//     }
    
//     bool hasdata(int data, BinaryTreeNode<int>*node){
//         if(node == NULL){
//             return false;
//         }
        
//         if(node->data == data){
//             return true;
//         }
//         bool check=false;
//         if(root->data>data){
//         	check=hasdata(data,root->left);    
//         }else{
//         	check=hasdata(data,root->right);    
//         }
//         return check;
//         // else if (node->data<data){
//         //     return hasdata(data, node->right);
//         // }else{
//         //     return hasdata(data,node->left);
//         // }
//     }

//     bool search(int data) {
// 		// Implement the search() function 
//         return hasdata(data, root);
//     }
// };
class BST {
    BinaryTreeNode<int>*root;
    // Define the data members
   public:
    BST() { 
        root=NULL;
        // Implement the Constructor
    }

	/*----------------- Public Functions of BST -----------------*/
	BinaryTreeNode<int>* deleteData(int data, BinaryTreeNode<int>* node) {
		if (node == NULL) {
			return NULL;
		}

		if (data > node->data) {
			node->right = deleteData(data, node->right);
			return node;
		} else if (data < node->data) {
			node->left = deleteData(data, node->left);
			return node;
		} else {
			if (node->left == NULL && node->right == NULL) {
				delete node;
				return NULL;
			} else if (node->left == NULL) {
				BinaryTreeNode<int>* temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			} else if (node->right == NULL) {
				BinaryTreeNode<int>* temp = node->left;
				node->left = NULL;
				delete node;
				return temp; 
			} else {
				BinaryTreeNode<int>* minNode = node->right;
				while (minNode->left != NULL) {
					minNode = minNode->left;
				}
				int rightMin = minNode->data;
				node->data = rightMin;
				node->right = deleteData(rightMin, node->right);
				return node;
			}
		}
	}
    void remove(int data) { 
        root=deleteData(data,root);
        // Implement the remove() function 
    }
 	void printhelp(BinaryTreeNode<int>*root){
        if(root==NULL){
            return;
        }
        cout<<root->data<<":";
        if(root->left!=NULL){
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right!=NULL){
            cout<<"R:"<<root->right->data;
        }
		cout<<endl;
        if(root->left!=NULL){
            printhelp(root->left);
        }
        if(root->right!=NULL){
            printhelp(root->right);
        }
    }
    void print() { 
        printhelp(root);
        // Implement the print() function
    }
	BinaryTreeNode<int>* inserthelp(BinaryTreeNode<int>*root,int data){
        if(root==NULL){
            BinaryTreeNode<int>*root1=new BinaryTreeNode<int>(data);
        	//root1->left=root1->right=NULL;
            return root1;
        }
        if(root->data>=data){
            root->left=inserthelp(root->left,data);
        }
        if(root->data<data){
            root->right=inserthelp(root->right,data);
        }
        return root;
    }
    void insert(int data) { 
        this->root=inserthelp(root,data);
        // Implement the insert() function 
    }
	bool searchhelp(BinaryTreeNode<int>*root,int data){
        if(root==NULL){
            return false;
        }
        if(root->data==data){
            return true;
        }
        bool check=false;
        if(root->data>data){
        	check=searchhelp(root->left,data);    
        }else{
        	check=searchhelp(root->right,data);    
        }
        return check;
    }
    bool search(int data) {
        return searchhelp(root,data);
		// Implement the search() function 
    }
};

int main() {
    BST *tree = new BST();
    int choice, input, q;
    cin >> q;
    while (q--) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->remove(input);
                break;
            case 3:
                cin >> input;
                cout << ((tree->search(input)) ? "true\n" : "false\n");
                break;
            default:
                tree->print();
                break;
        }
    }
}
