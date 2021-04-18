#include <iostream>
#include <string>
using namespace std;


string keypad(int n){
    if (n == 1){
        return "";
    }
    if(n == 2){
        return "abc";
    }
    if(n == 3){
        return "def";
    }
    if(n == 4){
        return "ghi";
    }
    if(n == 5){
        return "jkl";
    }
    if (n == 6){
        return "mno";
    }
    if (n == 7){
        return "pqrs";
    }
    if(n == 8){
        return "tuv";
    }
    if (n == 9){
        return "wxyz";
    }
}


void print_keypad_combination(int num, string output){
    if (num == 0){
        cout << output << endl;
        return; 
    }
    string input = keypad(num%10);
    for (int i =0; i<input.size();i++){
        print_keypad_combination(num/10, input[i]+output);
    }
}


void printKeypad(int num){
    string output;
    output = "";
    print_keypad_combination(num, output);
    
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}

