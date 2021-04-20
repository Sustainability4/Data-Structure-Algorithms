#include <iostream>
using namespace std;

void printsubs(int input[], int size, int output[], int m, int k ){
    if (size == 0){
        int sum = 0;
        for(int j = 0; j<m ; j++){
            sum = sum + output[j];
        }
        if (sum == k){
           for (int i = 0 ; i<m ; i++){
            cout << output[i]<< " ";
        } 
            cout << endl;
        }
        
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
    printsubs(input+1, size-1, new_output,n,k);
    printsubs(input+1, size-1, output, m,k);
}

void printSubsetSumToK(int input[], int size, int k) {
    // Write your code here
    int output [1000];
    int m = 0;
    printsubs(input,size, output,m, k );
}

int main() {
  int input[1000],length,k;
  cin >> length;
  for(int i=0; i < length; i++)
    cin >> input[i];
  cin>>k;
  printSubsetSumToK(input, length,k);
}
