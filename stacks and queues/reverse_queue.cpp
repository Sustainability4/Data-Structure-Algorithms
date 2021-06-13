#include<queue>
#include<stack>
#include<iostream>
using namespace std;
void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.size()==0){
        return;
    }
    stack<int> s;
    while(input.size()!=0){
        s.push(input.front());
        input.pop();
    }
    
    while(s.size()!=0){
        input.push(s.top());
        s.pop();
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        queue<int> q;
        int size;
        cin >> size;

        for (int i = 0, val; i < size; i++) {
            cin >> val;
            q.push(val);
        }

        reverseQueue(q);
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }

        cout << "\n";
    }
}
