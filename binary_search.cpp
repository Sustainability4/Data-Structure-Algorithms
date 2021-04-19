#include <iostream>
using namespace std;
int rBins ( int input[], int si, int ei, int element){
    if ( si == ei){
        if (input[si] == element){
            return si;
        }else {
            return -1;
        }
    }else {
        int mid = (si + ei)/2;
        if (input[mid]== element){
            return mid;
        }else if (element < input[mid] ){
            rBins(input, si, mid-1, element);
        }else {
            rBins(input, mid+1, ei, element);
        }
    }
}

int binarySearch(int input[], int size, int element) {
    // Write your code here
    int si = 0;
    int ei = size-1;
    
    if (size == 0){
        return -1;
    }else {
        int x = rBins(input, si, ei, element);
        return x;
    }
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
}

