#include <iostream>
using namespace std;
void merge(int input[], int si, int mid, int ei){
    int k = 0;
    int i = si;
    int j = mid+1;
    int new_array[ei-si+1];
    while(i<=mid && j<=ei){
        if(input[i]<input[j]){
            new_array[k]=input[i];
            k++;
            i++;
        }else if (input[j]<input[i]){
            new_array[k] = input[j];
            k++;
            j++;
        }else {
            new_array[k] = input[i];
            new_array[k+1] = input[j];
            k = k+2;
            i++;
            j++;
        }
    }
    if(i <= mid){
        for(i; i<= mid; i++){
            new_array[k] = input[i];
            k++;
        }
    }
    
    if(j <= ei){
        for(j; j<= ei; j++){
            new_array[k]= input[j];
            k++;
        }
    }
    
    int m = 0;
    int p = si;
    for(p;p <= ei; p ++){
        input[p] = new_array[m];
        m++;
    }
}

void sort(int input[], int si, int ei){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    sort(input,si,mid);
    sort(input,mid+1,ei);
    merge(input,si,mid,ei);
}

void mergeSort(int input[], int size){
    int si = 0;
    int ei = size-1;
    sort(input,si,ei);  
}

int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}
