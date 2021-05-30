#include <iostream>
using namespace std;

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

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while(t--)
	{
		Node *head = takeinput();
		head = reverseLinkedList(head);
		print(head);
	}

	return 0;
}
