#include <iostream>
#include<queue>
using namespace std;

bool has_path(int ** edges, int n, int v1, int v2){
    bool * visited = new bool[n];
    for(int i = 0; i<n; i++){
        visited[i] = false;
    }
    
    int count = 0;
    queue<int> q;
    q.push(v1);
    while(q.size()!=0 && count < n){
        //cout<<q.front()<<" ";
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
    
    if(visited[v1] == true && visited[v2]==true){
        return true;
    }else{
        return false;
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
    
    int v1, v2;
    cin>>v1>>v2;
    
    bool a = has_path(edges,n,v1,v2);
    
    if(a == 1){
        cout<<"true"<<endl;
    }else{
        cout<<"false"<<endl;
    }
    
}
