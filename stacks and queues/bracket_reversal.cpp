#include<stack>
#include<string>
#include<iostream>
using namespace std;

int countBracketReversals(string input) {
	// Write your code here
    stack<char> s;
    int count = 0;
    
    for(int i =0; i<input.size(); i++){
        if(input[i]=='{'){
            s.push('{');
        }
        
        if(input[i] == '}'){
            if(s.size()==0){
                s.push('}');
                count ++;
            }else {
                s.pop();
            }
        }
    }
    
    if(s.size() == 0){
        return count;
    }
    
    if(s.size()%2 == 0){
        return s.size()/2+count;
    }
    return -1;
}

int main() {
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}
