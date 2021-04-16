#include <iostream>
using namespace std;
int length(char string[]){
    if(string[0]=='\0'){
        return 0; 
    }
    int SmallStringLength = length(string+1);
    return SmallStringLength+1;
}
int main() {
    char str[100];
    cin>>str;
    int l = length(str);
    cout<<l<<endl;
}
