#include <iostream>
using namespace std;

string keypad_string(int n){
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

int keypad(int num, string output[]){
    if (num == 0){
        output[0] = "";
        return 1;
    }
    int smalloutput = keypad(num/10,output);
    int x = num%10;
    string str = keypad_string(x);
    for(int i = str.size()-1; i>=0; i--){
        for(int j = 0; j<smalloutput; j++){
            output[j + i*smalloutput] = output[j]+str[i];
        }
    }
    return smalloutput*(str.size());
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
