#include <iostream>
#include <queue>
using namespace std;

void print(int ** edges, int n, int sv, bool* visited){
    int count = 0;
    queue<int> q;
    q.push(sv);
    while(q.size()!=0 && count < n){
        cout<<q.front()<<" ";
        count +=1;
        visited[q.front()] = true;
        for(int i = 0 ; i<n ; i++){
        	if(i == q.front()){
            	continue;
        	}
        	if(edges[q.front()][i] == 1 && !visited[i]){
            	visited[i] = true;
            	q.push(i);
        	}
    	}
    	q.pop(); 
    }

}
int main() {
    int n ;
    int e ;
    cin >> n >> e;
    int ** edges = new int*[n];
    for(int i = 0; i<n ; i++){
        edges[i] = new int[n];
        for(int j = 0; j<n ; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0 ; i<e; i++){
        int f,s;
        cin>>f>>s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    bool * visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    
    
    
    if(n == 0){
        cout<<"";
    }else if(e == 0){
        for(int i = 0; i<n; i++){
            cout<<i<<" ";
        }
    }else{
        print(edges,n,0, visited);
    }
    
    // Delete All the Memory
    //delete[]visited;
}
