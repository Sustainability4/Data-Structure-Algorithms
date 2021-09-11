#include <iostream>
using namespace std;

#include <iostream>
using namespace std;
void print(int ** edges, int n, int sv, bool* visited){
    //cout<<sv<<endl;
    visited[sv] = true;
    for(int i = 0 ; i<n ; i++){
        if(i == sv){
            continue;
        }
        if(edges[sv][i] == 1){
            if(visited[i]){
                continue;
            }
            print(edges, n, i,visited);
        }
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

    print(edges,n,0, visited);
    int count = 0;
    for(int i = 0; i<n ; i++){
        if(visited[i]==false){
            cout<<"false";
            count = count+1;
            break;
        }
    }
    
    if(count == 0){
        cout<<"true";
    }
    
    
    // Delete All the Memory
    delete[]visited;
}
