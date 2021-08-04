#include<bits/stdc++.h>
using namespace std;

vector<int> parent(100000), size(100000);
vector<vector<int>> adj;

void make_set(int n){
    for(int i=0;i<=n;i++){
        parent[i] = i;
        size[i] = 0;
    }
}

int find_parent(int x){
    if(parent[x] == x) return x;
    return parent[x] = find_parent(parent[x]);
}

void union_dsu(int u, int v){
    u = find_parent(u);
    v = find_parent(v);
    if(size[u]>size[v]){
        parent[v] = u;
    }
    else if(size[v]>size[u]){
        parent[u] = v;
    }
    else{
        parent[u] = v;
        size[v]++;
    }
}

int main(){
    int v, e;
    cin>>v>>e;
    make_set(v);
    int m = e;
    int a, b, w, i;
    while(m--){
        cin>>w>>a>>b;
        adj.push_back({w, a, b});
    }
    sort(adj.begin(), adj.end());
    cout<<"--------------------------------"<<endl;
    for(i=0;i<e;i++){
        cout<<adj[i][0]<<": "<<adj[i][1]<<"->"<<adj[i][2]<<endl;
    }
    vector<vector<int>> st;
    for(i=0;i<e;i++){
        a = adj[i][1];
        b = adj[i][2];
        w = adj[i][0];
        if( find_parent(a) != find_parent(b) ){
            union_dsu(a, b);
            st.push_back({w, a, b});
        }
    }
    cout<<"--------------------------------"<<endl;
    for(i=0;i<st.size();i++){
        cout<<st[i][0]<<": "<<st[i][1]<<"->"<<st[i][2]<<endl;
    }
    cout<<"--------------------------------"<<endl;
}