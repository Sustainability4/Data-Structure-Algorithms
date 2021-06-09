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


class Stack {
	// Define the data members
    Node*head; 
    int count; 
    
   public:
    Stack() {
        // Implement the Constructor
        head = NULL;
        count = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return count;
        
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        return count == 0;
    }

    void push(int element) {
        // Implement the push() function
        
            Node*temp = new Node(element);
            temp->next = head;
            head = temp;
            count++;
        
    }

    int pop() {
        // Implement the pop() function
        if(isEmpty()){
            return -1;
        }else{
            Node*a = head; 
            head = head->next;
            int p = a->data;
            delete(a);
            count--;
            return p;
        }
    }

    int top() {
        // Implement the top() function
        if(isEmpty()){
            return -1;
        }else{
            return head->data;
        }
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}
