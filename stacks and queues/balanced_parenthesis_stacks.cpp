#include <iostream>
#include <string>
using namespace std;
#include<stack>
bool isBalanced(string expression) 
{
    // Write your code here
    if(expression[0]==')'){
        return false;
    }
    stack<char> c1;
    for(int i =0; i<expression.size(); i++){
        if(expression[i]=='('){
            c1.push('(');
        }else if (expression[i] == ')'){
            if(c1.top()=='('){
                c1.pop();  
            }else{
                return false; 
            }  
        }
    }
    
    if(c1.size()==0){
        return true;
    }else{
        return false;
    }
}

int main() 
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}
