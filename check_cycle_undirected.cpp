#include<bits/stdc++.h>
using namespace std;

bool dfs(int curr, int parent, vector<int> adj[], vector<bool> visited){
    if(visited[curr]) return true;

    visited[curr] = true;
    for(int i=0;i<adj[curr].size();i++){
        int x = adj[curr][i];
        if(x!=parent){
            
            if(dfs(x, curr, adj, visited)) return true;
        }
    }
    return false;
}

bool isCyclic(int V, vector<int> adj[]){
    vector<bool> visited(V, 0);
    return dfs(0, -1, adj, visited);
}

int main(){
    int V, e;
    cin>>V>>e;
    vector<int> adj[V];
    int i;
    for(i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool res = isCyclic(V, adj);
    res?cout<<"Cycle Present!!":cout<<"Cycle NOT Present!!";
}