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

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    if (head ==NULL || n == 0){
        return head;
    }else{
        Node*temp1 = head;
        int count = 0; 
        while(temp1 != NULL){
            temp1 = temp1->next;
            count ++;
        }
        Node * temp = head; 
        for (int i = 1; i<count-n ; i++){
            head = head->next;
        }
        Node*current = head->next;
        Node * a = head ->next;
        while (current->next != NULL){
            current = current->next;
        }
        current ->next = temp;
        head ->next = NULL;
        return a;
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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}
