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


int length(Node* head){
    if(head==NULL)
        return 0;
    
    return 1+length(head->next);
}

Node *bubbleSort(Node *head)
{
	// Write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    int a;
  //  int count = 0;
    Node* cur = head->next;
    Node* temp = head;
    int x = length(head);
    
    for(int i=1; i<=x; i++){
    while(cur != NULL)
    {
        if(cur->data < temp->data){
         
            a = temp->data;
            temp->data = cur->data;
            
            cur->data = a;
            
            temp = temp->next;
            cur = cur->next;
        }
        
        else{
             temp = temp->next;
            cur = cur->next;           
        }
    }
        temp=head;
        cur=temp->next;
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
