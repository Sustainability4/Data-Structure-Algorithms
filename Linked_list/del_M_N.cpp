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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
    
    if(M==0){
        Node*b = head;
        while(b != NULL && b->next !=NULL){
            Node*a = b->next;
            b->next = a->next;
            a->next = NULL;
            delete(a); 
        }
        
        delete(b);
        
        return NULL;
    }
    
    Node*temp = head;
    while(temp != NULL){
        
        for(int i = 0; i<M-1; i++){
            if(temp != NULL && temp->next != NULL){
                temp = temp->next;
            }else{
                break;
            }
            
        }
        
        for(int i =0; i<N; i++){
            if(temp != NULL && temp->next !=NULL){
                Node*a = temp->next;
                temp->next = a->next;
                a->next = NULL;
                delete(a);
            }else{
                break;
            }
           
        }
        if(temp != NULL){
            temp = temp->next;
        }
        
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
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}
