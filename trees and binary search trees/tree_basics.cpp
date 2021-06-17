#include <iostream>
using namespace std;
#include<queue>
#include<vector>

template <typename T>
class TreeNode(){

    public:
    T data;
    // If you want you can write <T> otherwise it will assume by-default 
    vector<TreeNode<T>*> children;

    TreeNode( T element){
        this->data = element;
    }

};

// taking input level wise

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<<"Enter root Data" << endl;
    cin >> rootData;

    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int> * front = pendingNodes.front();
        pendingNodes.pop();
        cout<<"Enter Number of Children of :" << front->data << endl;
        int numChild;
        cin>> numChild;

        for(int i = 0; i<numChild ; i++ ){
            int childData;
            cout<<"Enter the"<<i<<"th child of "<<front->data<<endl;
            cin>>childData;
            // We created this node dynamically because we want this memory to 
            // not de-allocate once the loop ends. 
            TreeNode<int> * child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }


}

// taking input non-level wise

TreeNode<int> takeInput(){
    int rootData;
    cout<<"Enter Data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    for(int i = 0; i<n ; i++){
        TreeNode<int> * child = takeInput();
        root->children.push_back(child);
    }

    return root; 
}

void printTree(){
    if(root == NULL){
        return;
    }
    cout<<root->data<<":";
    for(int i =0 ; i<root->children.size(); i++){
        cout << root->children[i]->data<<",";
    }

    cout<<endl;

    for(int i =0; i<root->children.size(); i++){
        printTree(root->children[i]);
    }
}
int main() {
    TreeNode<int> * root = new TreeNode<int>(1);
    TreeNode<int> * node1 = new TreeNode<int>(2);
    TreeNode<int> * node2 = new TreeNode<int>(3);
    root->children.push_back(node1);
    root->children.push_back(node2);

}
