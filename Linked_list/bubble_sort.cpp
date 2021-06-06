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

Node *bubbleSort(Node *head)
{
	// Write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    int count = 0;
    Node*cur = head;
    Node*prev = head;
    
    while(cur != NULL && cur->next != NULL){
        if(cur->data <= cur->next->data){
            prev = cur;
            cur = cur->next;
        }else{
            Node*a = cur->next;
            cur->next = a->next;
            a->next = cur;
            prev->next = a;
            prev = cur; 
            count++;
        }
    }
    
    if(count == 0){
        return head;
    }else{
        bubbleSort(head);
    }
    
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
	Node *head = takeinput();
	head = bubbleSort(head);
	print(head);
}
