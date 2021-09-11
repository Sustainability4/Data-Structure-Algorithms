#include <iostream>
#include<queue>
#include<stack>
using namespace std;
void getpathBFS(int ** edges, int n, int v1, int v2, bool*visited){
    int count = 0;
    queue<int> q;
    stack<int> s;
    q.push(v1);
    bool path_found = false;
    while(q.size()!=0 && (count < n && !path_found)){
        //cout<<q.front()<<" ";
        s.push(q.front());
        count +=1;
        visited[q.front()] = true;
        for(int i = 0 ; i<n ; i++){
        	if(i == q.front()){
            	continue;
        	}
        	if(edges[q.front()][i] == 1 && !visited[i]){
            	visited[i] = true;
            	q.push(i);
                if(i == v2){
                    path_found = true;
                    s.push(i);                
                }
        	}
    	}
    	q.pop(); 
    }
    
    while(s.size() != 0 && path_found){
        cout<<s.top()<<" ";
        s.pop();
    }
}

int main() {
    // Write your code here
        // Write your code here
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
    
    int v1,v2;
    cin>>v1>>v2;
    
   
    bool* visited = new bool[n];
    
    for(int i = 0; i<n ; i++){
        visited[i] = false;
    }
    
    getpathBFS(edges,n, v1, v2, visited);
}

