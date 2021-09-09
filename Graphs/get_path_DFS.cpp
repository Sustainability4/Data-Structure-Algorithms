#include <iostream>
#include<stack>
using namespace std;

void getpathDFS(int ** edges, int n, int v1, int v2, bool*visited, stack<int>&s){
    if(v1 == v2){
        s.push(v2);
        while(s.size() != 0){
            cout<<s.top()<<" ";
            s.pop();
        }
        
        for(int i = 0; i<n; i++){
            visited[i] = true;
        }
        return;
    }
    
    visited[v1] = true;
    s.push(v1);
    for(int i = 0 ; i<n ; i++){
        if(i == v1){
            continue;
        }
        
        if(edges[v1][i] == 1){
            if(visited[i]){
                continue;
            }
            getpathDFS(edges, n, i, v2, visited,s);
        }
    }
    
    return;
}

int main() {
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
    stack<int> s;
    getpathDFS(edges,n, v1, v2, visited, s);
}
