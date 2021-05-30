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

class Pair{
    public:
    Node*head;
    Node*tail;
};
// This is a very important peice of code for complexity basis O(n)
Pair reverse_ll2(Node*head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallans = reverse_ll2(head->next);
    smallans.tail->next = head;
    head->next = NULL;
    smallans.tail = head;
    return smallans;
}

Node* reverse_ll_better(Node*head){
    return reverse_ll2(head).head;
}

Node *reverseLinkedListRec(Node *head)
{
    //Write your code here
    if (head == NULL || head->next == NULL){
        return head;
    }
    
    head->next = reverseLinkedListRec(head->next);
    
    Node*temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    
    temp->next = head; 
    
    Node*a = head->next;
    
    head->next = NULL;
    
    return a;
    
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
		head = reverseLinkedListRec(head);
		print(head);
	}

	return 0;
}
