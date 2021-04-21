#include <iostream>
#include <string>
using namespace std;

void print(string input, string output){
    if (input.size()==0){
        cout<<output<<endl;
        return;
    }
    for(int i = 0; i<input.size(); i++){
        if(i == 0){
            print(input.substr(1),output+input[i]);
        }else if(i == input.size()-1){
            print(input.substr(0,i),output+input[i]);
        }else{
            print(input.substr(0,i)+input.substr(i+1),output+input[i]);
        }
    }
}

void printPermutations(string input){

    	/* Don't write main() function.
	 * Don't read input, it is passed as function argument.
	 * Print output as specified in the question
	*/
    string output;
    print(input, output);
    
}
int main() {
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}
