void DFS(int**edges, int n){
  bool * visisted = new bool[n];
  for(int i = 0; i<n ; i++){
    visited[i] = false;
  }
  
  for(int i = 0; i<n; i++){
    if(visited[i] == false){
      printDFS(edges,n,i,visited);
    }
  }
}

// Same way can be done for BFS as well 
