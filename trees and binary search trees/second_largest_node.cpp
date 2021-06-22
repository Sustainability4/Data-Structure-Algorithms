#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

/************************************************************

    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/
/*#include<stack>
#include<queue>
 
TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    queue<TreeNode<int>*> q;
    stack<TreeNode<int>*> s;
    
    q.push(root);
    TreeNode<int> *nxt = new TreeNode<int>(0);
    int low = 0;
    
    while(!q.empty()){
        
        TreeNode<int> *fr = q.front();
        q.pop();
        
        if(fr -> data > nxt -> data){
            s.push(fr);
            nxt = fr;
        }
        
        for(int i = 0; i < fr -> children.size(); i++){
            q.push(fr -> children[i]);
        }
    }
    if(s.empty()|| s.size() == 1){
        return NULL;
    }
    
    s.pop();
    return s.top();
    
}*/

template <typename T>
class SecondLargestReturnType{
    public:
    TreeNode<T> *largest;
    TreeNode<T> *secondlargest;
    
    SecondLargestReturnType(TreeNode<T> * first, TreeNode<T>* second){
        this->largest = first;
        this->secondlargest = second;
    }
    
};

SecondLargestReturnType<int> * getsecondlargestnodehelper(TreeNode<int>* root){
    if(root == NULL){
        return new SecondLargestReturnType<int>(NULL,NULL);
    }
    
    SecondLargestReturnType<int> *ans = new SecondLargestReturnType<int>(root,NULL);
    for(int i =0; i<root->children.size(); i++){
        SecondLargestReturnType<int>* childAns = getsecondlargestnodehelper(root->children[i]);
    
    
    if(childAns->largest->data > ans->largest->data){
        if(childAns->secondlargest == NULL){
            ans->secondlargest = ans->largest;
            ans->largest = childAns->largest;
        }else{
            if(childAns->secondlargest->data > ans->largest->data){
                ans->secondlargest = childAns->secondlargest;
                ans->largest = childAns->largest;
            }else{
                ans->secondlargest = ans->largest;
                ans->largest = childAns->largest;
            }
        }
    }else {
        if(ans->largest->data != childAns->largest->data && (ans->secondlargest == NULL || childAns->largest->data > ans->secondlargest->data)){
            ans->secondlargest = childAns->largest;
        }
    }
    }
    
    return ans;

}

TreeNode<int> * getSecondLargestNode(TreeNode<int> *root){
    return getsecondlargestnodehelper(root)->secondlargest;
}
 

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}
