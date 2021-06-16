#include <iostream>
class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

using namespace std;


Node *reverseLinkedList(Node *head) {
    // Iteratively
    
    if (head == NULL || head->next == NULL){
        return head;
    }
    Node*c = head;
    Node*n;
    Node*prev = NULL;
    
    while(c != NULL){
        n = c->next;
        c->next = prev;
        prev = c;
        c = n;
    }
    
    return prev;
}

Node* NextLargeNumber(Node *head) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    
    if(head->next == NULL){
        head->data = head->data+1;
        return head;
    }
    
    head = reverseLinkedList(head);
    
    Node*temp = head;
    
    int increament = 1; 
    
    while(temp->next != NULL){
        temp->data += 1;
        
        if(temp->data %10 == 0){
            increament = temp->data/10;
            temp = temp->next;
        }else{
            break;
        }
    }
    
    head = reverseLinkedList(head);
    
    return head;
    
}

Node* takeinput() {
    int data;
    cin >> data;
    Node* head = NULL, *tail = NULL;
    while(data != -1){
        Node *newNode = new Node(data);
        if(head == NULL)                  {
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
    cout<<endl;
}

int main() {
    Node *head = takeinput();
    
    head = NextLargeNumber(head);
    print(head);
    return 0;
}
