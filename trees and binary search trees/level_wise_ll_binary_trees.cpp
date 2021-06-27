#include <iostream>
#include <queue>
#include <vector>

template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
    queue<BinaryTreeNode<int>*> q;
    vector<Node<int>*> output;
    
    if(root==NULL){
        return output;
    }
    Node<int> *head=NULL;
    Node<int> *tail=NULL;
    q.push(root);
    q.push(NULL);
    while(q.size()!=0)
    {
        BinaryTreeNode<int> *current=q.front();
        
        if(current==NULL)
        {
            if(q.size()==1)
            {
                output.push_back(head);
                return output;
            }
            else{
                q.push(NULL);
                output.push_back(head);
                head=NULL;
                tail=NULL;
            }
        }
        else
        {
            Node<int> *temp=new Node<int>(NULL);
            temp->data=current->data;
            temp->next=NULL;
            if(head==NULL&&tail==NULL)
            {
                head=temp;
                tail=temp;
            }
            else{tail->next=temp;
                tail=tail->next;}
         if(current->left!=NULL)
        {
            q.push(current->left);
        }
        if(current->right!=NULL)
        {
            q.push(current->right);
        }
        }
        q.pop();      
    }    
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

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}
