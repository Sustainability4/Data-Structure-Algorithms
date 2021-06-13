
#include <iostream>
using namespace std;
#include<queue>
int main() {
    queue<int> q;
    //same as enqueue
    q.push(20);
    q.push(30);
    q.push(40);
    //front 
    cout<<q.front()<<endl;
    //delete element 
    q.pop();
    cout<<q.front()<<endl;
    //size
    cout<<q.size()<<endl;
    //checking empty 
    cout<<q.empty()<<endl;
}
