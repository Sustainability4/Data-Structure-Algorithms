#include <iostream>
class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;


Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
    if (head == NULL){
        return head;
    }
    head->next = deleteNodeRec(head->next, pos-1);
    if (pos == 0){
        Node *a = head->next; 
        delete(head);
        return a;
    }
    
    return head;
}

Node* insertNode(Node *head, int i, int data) {
	// Write your code here
    if (head == NULL){
        return head;
    }
    
    head->next = insertNode(head->next, i-1, data);
    
    if ( i == 0 && head != NULL){
        Node *c = head;
        Node * newData = new Node(data);
        head = newData;
        head ->next = c;
        return head;
    }
    
    return head;
    
}

int length(Node *head) {
    // Write your code here
    if (head == NULL){
        return 0; 
    }
    
    int i = length(head->next);
    
    return i+1;
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        Node *head = takeinput();
        cout << length(head) << "\n";
        head = insertNode(head, pos, data);
        print(head);
        int pos;
		cin >> pos;
		head = deleteNodeRec(head, pos);
		print(head);
    }
}
