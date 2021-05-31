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

Pair reverse(Node*head){
    if(head == NULL || head->next == NULL){
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }

    Pair smallans = reverse(head->next);
    smallans.tail->next = head;
    head->next = NULL;
    smallans.tail = head;
    return smallans;
}

int len(Node *head)
{
    //Write your code here
    Node *temp = head;
    int i = 0;
    while(temp != NULL){
        temp = temp->next;
        i++;
    }
    return i; 
}

Node *kReverse(Node *head, int k)
{
	//Write your code here
    if(k>=len(head)){
        Pair h1 = reverse(head);
        return h1.head; 
    }
    
    Node*h1 = head;
    Node*t1 = head;
    Pair H;
    
    for(int i =0; i<k-1 ; i++){
        t1 = t1->next;
    }
    
    Node*a = t1->next;
    t1->next = NULL;
    H = reverse(h1);
    H.tail->next = kReverse(a, k);
    
    return H.head; 
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
		int k;
		cin >> k;
		head = kReverse(head, k);
		print(head);
	}
	
	return 0;
}
