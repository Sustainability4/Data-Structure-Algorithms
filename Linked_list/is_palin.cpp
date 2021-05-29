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


bool isPalindrome(Node *head)
{
    //Write your code here
    
    if(head == NULL || head->next == NULL){
        return true;
    }
    
    Node*temp = head; 
    Node*a = head;
    int count =1; 
    while (temp->next != NULL){
        temp = temp->next;
        count ++;
    }
    
    int mid = count/2;
    
    int p = count-1;
    
    for(int i =0; i<mid; i++){
        if(a->data == temp->data){
            a = a->next;
            Node*current= head;
            for (int j =1; j<p;j++){
                current = current->next;
            }
            temp->next = current; 
            temp = temp->next;
            p = p-1;
        }else {
            return false;
        }
    }
    
    return true;
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
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}
