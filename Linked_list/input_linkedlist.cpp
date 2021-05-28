#include <iostream>
using namespace std;
class Node {
    public:
    int data;
    Node*next;

    Node(int data){
        this -> data = data;
        next = NULL;
    }

};

void print(Node* head){
    Node * temp = head;
    while (temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

Node* takeInput(){
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1){
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
        }else {
            Node*temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp -> next = newNode;
        }
        cin >> data;
    }
    return head;
}

// More efficient way of writing this code using tail node
Node* takeInput1(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1){
        Node *newNode = new Node(data);
        if (head == NULL){
            head = newNode;
            tail = newNode;
        }else {
            tail -> next = newNode;
            tail = tail->next;
            }
        }
        cin >> data;
    }
    return head;
}
int main() {
    // Statically 
    Node n1(1);
    Node*head = &n1;
    Node n2(2);
    n1.next = & n2;
    

    cout << n1.data << " " << n2.data << endl;
    cout << head -> data << " " << 
    //cout << *n1.next << endl;

    // Dynamically 
    Node * n3 = new Node(10);
    Node * head = n3;
    Node * n4 = new Node(20);
    n3 -> next = n4;

}

