#include <iostream>
using namespace std;

#include<stack>
int* stockSpan(int *price, int size)  {
	// Write your code here
    stack<int> s;
    int* array = new int[size];
    for(int i =0;i<size;i++){
        if(i == 0){
            s.push(i);
            array[i] = 1;
        }else{
            if(price[s.top()]>=price[i]){
                array[i] = i-s.top();
                s.push(i);
            }else{
                while(s.size()!=0){
                    int a = s.top();
                    if(price[a]>=price[i]){
                        array[i] = i-a;
                        s.push(i);
                        break;
                    }
                    s.pop();
                }
                if(s.size() == 0){
                    array[i] = i+1;
                    s.push(i);
                }
                
            }
        }   
    }
    
    return array;
}

int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
