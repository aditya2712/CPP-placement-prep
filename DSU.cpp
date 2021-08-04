#include <bits/stdc++.h>
using namespace std;

// rank is reserved by library so instead of rank we use rnk !!
vector<int> rnk(100000);
vector<int> parent(100000);

void make_set(int n){
    for(int i = 0; i <= n; i++){
        parent[i] = i;
        rnk[i] = 0;
    }
}

int find_par(int x){
    if(parent[x] == x) return x;

    return parent[x] = find_par(parent[x]);
}

void union_dsu(int u, int v){
    u = find_par(u);
    v = find_par(v);
    if(rnk[u]>rnk[v]){
        parent[v] = u;
    }
    else if(rnk[v]>rnk[u]){
        parent[u] = v;
    }
    else{
        parent[u] = v;
        rnk[v]++;
    }
}

int main(){
    int n;
    cin >> n;
    make_set(n);
    int option = 1;
    while(option){
        cin>>option;
        if(option == 1){
            int a, b;
            cin>>a>>b;
            union_dsu(a,b);
        }
        else if(option == 2){
            int x;
            cin>>x;
            cout<<"parent of "<<x<<": "<<find_par(x)<<endl;
        }
        else{
            break;
        }
    }
}