#include <string.h>
#include <bits/stdc++.h>
using namespace std;

void print(string input,string output){
    if(input.size()==0){
        cout<<output<<endl;
        return;
    }
    int a = input[0];
    a = a-48;
    char c1 = 'a'+a-1;
    print(input.substr(1),output+c1);
    if(input.size()>1){
        int b1 = input[0]-48;
        int b2 = input[1]-48;
        int b = b1*10+b2;
        if (b>=10, b<= 26){
            char c2 = 'a'+b-1;
            print(input.substr(2),output+c2);  
        }
        
    } 
}

void printAllPossibleCodes(string input) {
    /*
    Given the input as a string, print all its possible combinations. You do not need to return anything.
    */
    string output;
    print(input,output);
    
}
int main(){
    string input;
    cin >> input;

    printAllPossibleCodes(input);
    return 0;
}
