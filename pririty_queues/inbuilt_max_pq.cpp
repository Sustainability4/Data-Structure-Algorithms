#include <iostream>
using namespace std;
#include<queue>
int main() {
    priority_queue<int> pq;
    // empty is used for determining whenther priority queue is empty or not 
    // insert function is push 
    // getSize is size
    // Inbuilt priority queue is by default is max priority queue
    // top function will give the maximum element 
    // pop function will remove the maximum priority element

    pq.push(1);
    pq.push(16);
    pq.push(45);
    pq.push(32);
    pq.push(5);

    cout<<"Size : " << pq.size()<<endl;
    cout<<"Topmost element :" << pq.top()<<endl;

    // Now max priority queue is inbuilt, how we will use our min priority queue.
    
}
