#include<bits/stdc++.h>
using namespace std;

int main(){
    int V, e;
    cin>>V>>e;
    vector<pair<int, int>> adj[V];
    int i;
    for(i=0;i<e;i++){
        int w, v, u;
        cin>>w>>u>>v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> parent(V), key(V);
    vector<bool> mst(V);
    
    for(i=0;i<V;i++){
        parent[i] = -1;
        key[i] = INT_MAX;
        mst[i] = false;
    }

    key[0] = 0;

    // We can use Priority queue using min heap, 
    // so as to reduce time complexity of the chosing minimum element everytime
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; 
    pq.push({0,0});

    for(int count = 0; count<V-1 ;count++){
        int u;
        
        // While we don't get a node which haven't been included in mst
        while(1){
            u = pq.top().second;
            pq.pop();
            if(!mst[pq.top().second]) break;
        }
        mst[u] = true;

        for(auto it:adj[u]){
            int w = it.second;
            int v = it.first;
            if(!mst[v] && key[v]>w){
                key[v] = w;
                parent[v] = u;
                pq.push({key[v], v});
            }
        }
    }

    int cost = 0;
    cout<<"--------------------------\n";
    for(i=1;i<V;i++){
        cost += key[i];
        cout<<key[i]<<": "<<parent[i]<<"->"<<i<<endl;
    }
    cout<<"--------------------------\n";
    cout<<cost<<endl;
    cout<<"--------------------------\n";
}

// Sample Input
// --------------------------
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

// Sample Output
// --------------------------
// 4: 0->1
// 8: 1->2
// 7: 2->3
// 9: 3->4
// 4: 2->5
// 2: 5->6
// 1: 6->7
// 2: 2->8
// --------------------------
// 37
// --------------------------