#include <iostream>
using namespace std;
int array_length ( char input[]){
    int i = 0;
    while(input[i]){
        i++;
    }
    return i;
}


bool check_AB(char input[], int size){
    if (size == 0){
        return true;
    }
    
    if (input[0] == 'a'){
        if(input[1] == 'a'){
            check_AB(input+1,size-1);
        }else if (input[1] == 'b' && input[2] == 'b'){
            check_AB(input+3, size-3);
        }else if (size == 1){
            return true;
        }else{
            return false;
        }
    }else{
        return false;
    }
}


bool checkAB(char input[]) {
	// Write your code here
    int size = array_length(input);
    if (size == 0){
        return false;
    }else{
        bool val = check_AB(input, size);
    }
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
}
