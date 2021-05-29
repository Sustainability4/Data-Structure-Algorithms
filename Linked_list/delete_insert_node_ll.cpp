#include <iostream>

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

using namespace std;
#include "solution.h"

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

Node* InsertNode(Node * head, int i , int data){
    Node * newData = new Node(data);
    Node *current = head;
    int count = 0;

    if (i == 0){
        newData -> next = head;
        head = newData;
        return head;
    }
    while (current != NULL && count < i-1){
        current = current -> next;
        count ++;
    }
    if (current != NULL){
        newData -> next  = current -> next; 
        current -> next = newData;
    }

    return head;
}

Node *deleteNode(Node *head, int pos)
{
    //Write your code here
    Node *temp = head;
    int count = 0;
    if ( pos == 0 && head != NULL){
        head = head->next;
        return head; 
    }
    
    while (temp != NULL && count < pos-1){
        temp = temp->next;
        count ++;
    }
    
    if (temp != NULL && temp->next !=NULL){
        Node *a = temp->next;
        Node*b = a -> next;
        temp -> next = b;
        delete(a);
    }
    
    return head;
}
void printIthNode(Node *head, int i)
{
    //Write your code here
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == i)
            cout<< current->data;
        count++;
        current = current->next;
    }    
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		printIthNode(head, pos);
		cout << endl;
	}
    head = InsertNode(head, 0,99);
	return 0;
}
