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

Node *evenAfterOdd(Node *head)
{
	//write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node*OH = NULL;
    Node*OT = NULL;
    Node*EH = NULL;
    Node*ET = NULL;
    Node*temp = head;
    
    while(temp!=NULL){
        
        if(temp->data % 2 == 0){
            if(EH == NULL && ET == NULL){
                EH = temp;
                ET = temp;
            }else{
                ET->next = temp;
                ET = ET->next;
            }
        }else{
            if(OH == NULL && OT == NULL){
                OH = temp;
                OT = temp;
            }else{
                OT->next = temp;
                OT = OT->next;
            }
        }
        
        temp = temp->next;
    }
   
    if(OH == NULL){
        ET->next = NULL;
        return EH;
    }else if(EH == NULL){
        OT->next = NULL;
        return OH;
    }else{
        ET->next = NULL;
        OT->next = EH;
        return OH; 
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
		Node *head = takeinput();
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}
