#include <iostream>
using namespace std;
class StackUsingArray {

    int*data;
    int nextIndex;
    int capacity;

    public:
    // If we want to create a stack dynamically, we need our user not to enter
    // any size whatsoever. For this we need to take a random capacity value 
    // lets say we took 4 as the value of capacity 
    StackUsingArray(){
        data = new int[4];
        nextIndex = 0;
        capacity = 4;
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
            // We should double our stack capacity
            int newdata = new int[capacity*2];
            for(int i =0 ; i<capacity ; i++){
                newdata[i] = data[i];
            }
            capacity *= 2;
            delete [] data;
            data = newdata;
            /*cout<<"Stack is already full"<<endl;
            return;*/
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
