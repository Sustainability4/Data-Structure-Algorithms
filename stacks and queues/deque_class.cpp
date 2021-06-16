#include<iostream>
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

class Deque {
	// Define the data members
    Node*head; 
    Node*tail;
    int size; 
    int capacity;
    
   public:
    Deque(int element) {
		// Implement the Constructor
        head = NULL; 
        tail = NULL;
        size = 0;
        capacity = element;
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

    void insertRear(int data) {
		// Implement the enqueue() function
        Node*temp = new Node(data);
        if(size==0){
            head = temp;
            tail = temp;
            size++;
            return;
        }
        
        if(size == capacity){
            cout<<-1<<endl;
            return;
        }
        
        tail->next = temp;
        tail = tail->next;
        size++;
	}
    
    
    void insertFront(int element){
        Node*temp = new Node(element);
        
        if(size ==0){
            head = temp;
            tail = temp;
            size++;
            return; 
        }
        
        if (size == capacity){
            cout<<-1<<endl;
            return;
        }
        
        temp->next = head;
        head = temp;
        size++;
    }
    
    

    int deleteFront() {
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
    
    int deleteRear(){
        if(size==0){
            return -1;
        }
        
        Node*temp = head;
        
        while(temp->next != tail){
            temp = temp->next;
        }
        
        int a = tail->data;
        temp->next = NULL;
        delete(tail);
        
        tail = temp;
        size--;
        return a;
        
    }

    int getFront() {
        if (size == 0){
            return -1;
        }
        // Implement the front() function
        return head->data;
    }
    
    int getRear(){
        if(size == 0){
            return -1;
        }
        
        return tail->data;
    }
};

int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}

