#include<iostream>
using namespace std;

void printsubs(int input[], int size, int output[], int m ){
    if (size == 0){
        for (int i = 0 ; i<m ; i++){
            cout << output[i]<<" ";
        }
        cout << endl;
        return;
    }
    int new_output[1000];
    for(int i = 0;i<=m; i++){
        new_output[i] = output[i];
    }
    int n = m;
    new_output[m+1] = new_output[m];
    new_output[m] = input[0];
    n = n+1;
    printsubs(input+1, size-1, new_output,n);
    printsubs(input+1, size-1, output, m);
}


void printSubsetsOfArray(int input[], int size) {
	// Write your code here
    int output[1000];
    int m = 0;
    printsubs(input, size, output,m);
    
    
}
int main() {
  int input[1000],length;
  cin >> length;
  for(int i=0; i < length; i++)
  	cin >> input[i];
  printSubsetsOfArray(input, length);
}
