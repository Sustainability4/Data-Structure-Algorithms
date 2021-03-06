#include <iostream>
using namespace std;
template<typename T>
class QueueUsingArray{
    T*data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public:
    QueueUsingArray(int s){
        capacity = s;
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
    }

    int getSize(){
        return size;
    }

    bool isEmpty(){
        return size == 0;
    }

    // insert an element 

    void enqueue(T element){
        if(size == capacity){
            int temp = firstIndex;
            T*newdata = new T[capacity*2];
            for(int i =0; i <capacity; i++){
                newdata[i] = data[temp];
                temp = (temp+1)%capacity;
            }
            data = newdata;
            firstIndex = 0;
            nextIndex = capacity;
            capacity = capacity*2;
            return;
        }
        data[nextIndex]= element;
        nextIndex = (nextIndex+1)%capacity;
        if (firstIndex==-1){
            firstIndex = 0;
        }
        size ++;
    }

    // front Function 

    T front(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        return data[firstIndex];
    }

    T dequeue(){
        if(isEmpty()){
            cout<<"queue is empty"<<endl;
            return 0;
        }
        T a = data[firstIndex];
        firstIndex = (firstIndex+1)%capacity;
        size--;
        if(size == 0){
            firstIndex = -1;
            nextIndex = 0;
        }
        return a;
    }

};
int main() {
    cout<<"Hello World!";
}
