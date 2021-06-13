#include <iostream>
using namespace std;

class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

/************************************************************
 
    Following is the structure of the node class 
 
    class Node {
    	public :
    	int data;
    	Node *next;

    	Node(int data) {
        	this->data = data;
        	next = NULL;
    	}
	};

**************************************************************/

class Queue {
	// Define the data members
    Node*head; 
    Node*tail;
    int size; 
   public:
    Queue() {
		// Implement the Constructor
        head = NULL; 
        tail = NULL;
        size = 0;
	}
	
	/*----------------- Public Functions of Stack -----------------*/

	int getSize() {
		// Implement the getSize() function
        return size;
	}

    bool isEmpty() {
		// Implement the isEmpty() function
        return size == 0;
	}

    void enqueue(int data) {
		// Implement the enqueue() function
        Node*temp = new Node(data);
        if(size==0){
            head = temp;
            tail = temp;
            size++;
            return;
        }
        
        tail->next = temp;
        tail = tail->next;
        size++;
	}

    int dequeue() {
        // Implement the dequeue() function
        if(size == 0){
            return -1;
        }
        int a = head->data;
        Node*temp = head;
        head = head->next;
        delete(temp);
        size--;
        return a; 
    }

    int front() {
        if (size == 0){
            return -1;
        }
        // Implement the front() function
        return head->data;
    }
};

int main() {
    Queue q;

    int t;
    cin >> t;

    while (t--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                q.enqueue(input);
                break;
            case 2:
                cout << q.dequeue() << "\n";
                break;
            case 3:
                cout << q.front() << "\n";
                break;
            case 4:
                cout << q.getSize() << "\n";
                break;
            default:
                cout << ((q.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
