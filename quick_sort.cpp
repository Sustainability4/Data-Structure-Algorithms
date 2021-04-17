#include <iostream>
using namespace std;

int partition(int input[], int si, int ei){
    int x = input[si];
    int i =si+1;
    int c = 0;
    while(i<=ei){
        if(input[i]<=x){
            c++;
        }
        i++;
    }
    input[si] = input[si+c];
    input[si+c] = x; 
    int m = si;
    int n = ei;
    while(m<c+si && n>c+si){
        if(input[m]<=x){
            m++;
        }else if (input[n]>x){
            n--;
        }else{
            int p = input[n];
            input[n] = input[m];
            input[m] = p;
            n--;
            m++;
        }
    }
    return c+si;
}
void qs(int input[], int si, int ei){
    if (si>=ei){
        return;
    }
    int c = partition(input, si, ei);
    qs(input,si,c-1);
    qs(input, c+1,ei);
    
}

void quickSort(int input[], int size) {
    int si = 0;
    int ei = size-1;
    qs(input, si, ei);

}
void mergeSort(int input[], int size){
    int si = 0;
    int ei = size-1;
    sort(input,si,ei);  
}

int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}

