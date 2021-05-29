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


void printReverse(Node *head)
{
    //Write your code here
    
    if (head == NULL){
        return; 
    }
    
    if (head->next == NULL){
        cout << head->data <<" ";
        return;
    }
    
    
    Node*temp= head; 
    int count =0; 
    while (temp->next != NULL){
        temp = temp->next;
        count ++;
    }
    Node*a = temp;
    int p = count-1;
    
    for(int i =0; i<count; i++){
        Node*current = head;
        for (int j =0; j<p;j++){
            current = current->next;
        }
        a->next = current; 
        a = a->next;
        p = p-1;
    }
    
    a->next = NULL;
    
    for (int i =0 ; i <=count ; i++){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}
