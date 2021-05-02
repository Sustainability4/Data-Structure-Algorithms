#include <iostream>
using namespace std;

void rotate(int *input, int d, int n)
{
    //Write your code here
    int si = 0;
    int ei = n-1;
    while(si<ei){
        int m = input[si];
        input[si]= input[ei];
        input[ei] = m;
        si++;
        ei--;
    }
    int a = 0;
    int b = n-d-1;
    while(a<b){
        int m = input[a];
        input[a] = input[b];
        input[b] = m;
        a++;
        b--;
    }
    
    int a1 = n-d;
    int b1 = n-1;
    while(a1<b1){
        int m = input[a1];
        input[a1] = input[b1];
        input[b1] = m;
        a1++;
        b1--;
    }
}

int main()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int size;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		int d;
		cin >> d;

		rotate(input, d, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}
		
		delete[] input;
		cout << endl;
	}

	return 0;
}
