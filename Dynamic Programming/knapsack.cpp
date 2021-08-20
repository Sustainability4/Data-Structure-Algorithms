#include <cstring>
#include <iostream>
using namespace std;

int knapsack(int* weight, int* value, int n, int maxWeight) {
	// Write your code here
    if(n == 0){
        return 0;
    }

    int **ans = new int*[n+1];
	for(int i = 0; i < n+1; i++) {
		ans[i] = new int[maxWeight+1];
	}
    
    for (int i = 0 ; i<maxWeight+1; i++){
        ans[n][i] = 0;
    }
    
    for(int i = 0 ; i<n+1; i++){
        ans[i][0] = 0;
    }
    
    for (int i = n-1; i>=0; i--){
        for(int j = maxWeight; j>0; j--){
            int case_1 = ans[i+1][j];
            int case_2 = 0;
            if(weight[i]<=j){
                case_2 = ans[i+1][j-weight[i]]+value[i];
            }
            ans[i][j] = max(case_1,case_2);
        }
    }
    
    return ans[0][maxWeight];
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}
