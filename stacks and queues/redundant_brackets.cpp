#include <iostream>
#include <string>
using namespace std;
#include<stack>
bool checkRedundantBrackets(string expression) {
	// Write your code here
    
    stack<char> s; 
    for(int i =0; i<expression.size(); i++){
        if(expression[i] == ')'){
            int count = 0;
            while(s.top() != '('){
                s.pop();
                count++;
            }
            if(count != 0 && count != 1){
                s.pop();
            }else{
                return true;
            }
        }else{
            s.push(expression[i]);
        }
    }
    return false;
}

int main() {
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}
