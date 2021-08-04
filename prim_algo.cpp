#include<bits/stdc++.h>
using namespace std;

int main(){
    int V, e;
    cin>>V>>e;
    int i;
    vector<pair<int, int>> adj[V];
    vector<int> parent(V), key(V);
    vector<bool> mst(V);   
    
    for(i=0;i<e;i++){
        int u, v, w;
        cin>>w>>u>>v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    cout<<"--------------------------------"<<endl;
    // initialize each parent to -1, key to INF, mst to false
    for(i=0;i<V;i++){
        parent[i] = -1;
        key[i] = INT_MAX;
        mst[i] = false;
    }
    key[0] = 0;

    // As in a MST only V-1 edges are there hence we will iterate for each edge
    for(int count=0;count<V-1;count++){
        int mini = INT_MAX, u;  
        
        for(i=0;i<V;i++)
            if(mst[i] == false && key[i]<mini){
                mini = key[i];
                u= i;
            }

        mst[u] = true;

        for(auto it:adj[u]){
            int w = it.second;
            int v = it.first;
            if(mst[v] == false && key[v]>w){
                key[v] = w;
                parent[v] = u;
            }
        }     
    }
    int cost = 0;
    cout<<"--------------------------------"<<endl;
    for(i=1;i<V;i++){
        cost+=key[i];
        cout<<key[i]<<": "<<parent[i]<<"->"<<i<<endl;
    }
    cout<<cost<<endl;
    cout<<"--------------------------------"<<endl;
}

// Sample Input
// 9 14
// 1         7      6
// 2         8      2
// 2         6      5
// 4         0      1
// 4         2      5
// 6         8      6
// 7         2      3
// 7         7      8
// 8         0      7
// 8         1      2
// 9         3      4
// 10        5      4
// 11        1      7
// 14        3      5