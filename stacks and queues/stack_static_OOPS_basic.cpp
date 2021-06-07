#include <iostream>
using namespace std;
class StackUsingArray {
    
    int*data;
    int nextIndex;
    int capacity;

    public:
    StackUsingArray(int totalSize){
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
    }

    // Return the number of elements in my stack
    int size(){
        return nextIndex;
    }

    bool IsEmpty(){
        /*
        if(nextIndex == 0){
            return true;
        }
        else {
            return false;
        }
        */

        return nextIndex == 0;
    }

    // Insert element

    void push(int element){
        if (nextIndex == capacity){
            cout<<"Stack is already full"<<endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex ++;
    }

    // Delete the element 

    int pop(){
        if(nextIndex == 0){
            cout<<"stack is empty"<<endl;
            return INT_MIN; 
        }
        nextIndex--;
        return data[nextIndex];
    }

    // Topmost element of the stack

    int top(){
        if(nextIndex == 0){
            cout<<"stack is empty"<< endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

};
int main() {
    cout<<"Hello World!";
}
