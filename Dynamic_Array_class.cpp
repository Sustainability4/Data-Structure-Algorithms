#include <iostream>
using namespace std;
class DynamicArray{
    int * data;
    int capacity;
    int nextIndex;

    public: 

    DynamicArray(){
        data = new int[5];
        nextIndex = 0;
        capacity = 5; 
    }

    void add(int element){
        if(nextIndex == capacity){
            int * newData = new int[capacity*2];
            for (int i =0; i<capacity ; i++){
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
            capacity = 2*capacity;
        }
        data[nextIndex] = element;
        nextIndex ++; 
    }

    int get const(int index){
        if(index < nextIndex){
            return data[index];
        }else {
            return -1;
        }
    }

    void add(int i, int element){
        if (i < nextIndex){
            data[i] = element;
        }else if (i == nextIndex){
            add(element);
        }else { 
            return; 
        }
    }

    void print() const{
        for(int i =0 ; i<nextIndex ; i++){
            cout<<data[i]<<endl;
        }
    }

    // Deep Copy Constructor 
    DynamicArray(DynamicArray const &d){
        // this -> data = d.data; This is a shallow copy 
        this -> data = new int[d.capacity];
        for (int i = 0; i<d.nextIndex ; i++){
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }

    // Copy Assignment Operator 

    void Operator=(DynamicArray const &d){
        this -> data = new int[d.capacity];
        for (int i = 0; i<d.nextIndex ; i++){
            this -> data[i] = d.data[i];
        }
        this -> nextIndex = d.nextIndex;
        this -> capacity = d.capacity;
    }
};
int main() {
    DynamicArray d1;
    d1.add(10);
    d1.add(20);
    d1.add(30);

    DynamicArray d2(d1); // copy constructor but shallow copy 

    d1.add(0,40);

    d2.print();

}
