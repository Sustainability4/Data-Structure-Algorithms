#include <string.h>
using namespace std;

int getCodes(string input, string output[10000]) {
    /*
    You are given the input text and output string array. Find all possible codes and store in the output string array. Don’t print the codes.
    Also, return the number of codes return to the output string. You do not need to print anything.
    */
    if (input.size()==0){
       output[0] = "";
       return 1; 
    }
    int k =0;
    int a1 = input[0];
    a1 = a1-48;
    char c1 = 'a'+a1-1;
    string smalloutput1[10000], smalloutput2[10000];
    if(input.size()>1){
        int b1 = input[0];
        b1 = b1-48;
        int b2 = input[1];
        b2 = b2-48;
        int b = b1*10+b2;
        if(b>=10,b<=26){
            char c2 = 'a'+b-1;
            int r2 = getCodes(input.substr(2),smalloutput2);
            for(int i = 0; i<r2 ; i++){
                output[k] = c2+ smalloutput2[i];
                k++;
            }
        }
        
    }
    int r1 = getCodes(input.substr(1),smalloutput1);
    for(int i =0; i<r1; i++){
        output[k]= c1+smalloutput1[i];
        k++;
    }
    return k; 
}
int main(){
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for(int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}


