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
/*int partition(int input[], int si, int ei){
    int x = input[si];
    int i =si+1;
    int c = 0;
    while(i<=ei){
        if(input[i]<=x){
            c++;
        }
        i++;
    }
    input[si] = input[si+c];
    input[si+c] = x; 
    int m = si;
    int n = ei;
    while(m<c+si && n>c+si){
        if(input[m]<=x){
            m++;
        }else if (input[n]>x){
            n--;
        }else{
            int p = input[n];
            input[n] = input[m];
            input[m] = p;
            n--;
            m++;
        }
    }
    return c+si;
}
void qs(int input[], int si, int ei){
    if (si>=ei){
        return;
    }
    int c = partition(input, si, ei);
    qs(input,si,c-1);
    qs(input, c+1,ei);
    
}

void quickSort(int input[], int size) {
    int si = 0;
    int ei = size-1;
    qs(input, si, ei);

}


int getarray(int * array, BinaryTreeNode<int>*root, int current_size){
    if(root == NULL){
        return 0; 
    }
    
    int array_left[];
    int array_left[];
    
    
}
#include<algorithm>
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    
    int a[1000];
    int size = getarray(a, root, 0);
    sort(a,a+size);
    
    int i = 0;
    int j = size-1;
    
    for(int i = 0; i<size; i++){
        cout<<a[i]<<" ";
    }
    
    
    while(i<j){
        if((a[i]+a[j])>sum){
            j--;
        }else if((a[i]+a[j])<sum){
            i++;
        }else{
            cout<<a[i]<<" "<<a[j]<<" "<<endl;
            i++;
            j--;
        }
    }
}*/
#include<algorithm>

void helper(BinaryTreeNode<int>*root,vector<int>&output){
    if(root==NULL){
        return;
    }
    output.push_back(root->data);
    helper(root->left,output);
    helper(root->right,output);
}


void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
    if(root==NULL){
        return;
    }
    vector<int>output;
    helper(root,output);
    sort(output.begin(),output.end());
     int i = 0;
     int j = output.size()-1;
    while(i<j){
        if(output[i] + output[j] == sum){
            cout<<output[i]<<" "<<output[j]<<endl;
            i++;
            j--;
        }
        if(output[i]+output[j] < sum){
            i++;
        }
        if(output[i] + output[j] > sum){
            j--;
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}
