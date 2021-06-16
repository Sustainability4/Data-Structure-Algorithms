#include <iostream>

class Node {
public:
    int data;
    Node * next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
    
    ~Node() {
        if(next) {
            delete next;
        }
    }
};

using namespace std;



void deleteAlternateNodes(Node *head) {
    //Write your code here
    
    if(head == NULL || head->next == NULL){
        return;
    }
    Node*temp = head;
    while(temp->next != NULL && temp != NULL){
        Node*a = temp->next; 
        if(a->next != NULL){
            temp->next = a->next;
            a->next = NULL;
            temp = temp->next;
        }else{
            temp->next = NULL;
        }
        
        delete(a);
        
    }
    
}


Node* takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else{
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main() {
    Node *head = takeinput();
    deleteAlternateNodes(head);
    print(head);
    delete head;
    return 0;
}
