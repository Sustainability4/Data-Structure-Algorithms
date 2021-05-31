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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(i == 0 || j== 0){
        if(i==0){
            Node*t2 = head;
            Node*t1 = head;
             for(int k = 0; k<j-1; k++){
                 t2 = t2->next;
             }
            Node*b = t2->next;
            Node*c = b->next;
            b->next = t1->next;
            t1->next = c;
            t2->next = t1;
            
            return b;
            
        } else{
             Node*t2 = head;
            Node*t1 = head;
             for(int k = 0; k<i-1; k++){
                 t2 = t2->next;
             }
            Node*b = t2->next;
            Node*c = b->next;
            b->next = t1->next;
            t1->next = c;
            t2->next = t1;
            
            return b;
            
        }
    }
    Node*t1 = head;
    Node*t2 = head;
    for(int k =0; k<i-1;k++){
        t1 = t1->next;
    }
    
    for(int k = 0; k<j-1; k++){
        t2 = t2->next;
    }
    
    Node*a = t1->next;
    Node*b = t2->next;
    Node*c = b->next;
    t1->next = b;
    t2->next = a;
    b->next = a->next;
    a->next = c;
    
    return head;
    
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
	while (t--)
	{
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}
