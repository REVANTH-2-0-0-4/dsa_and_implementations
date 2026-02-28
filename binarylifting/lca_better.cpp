#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;
vector<int> parent;
vector<int> level;
vector<vector<int>> child;
vector<vector<int>> table;
const int lg = 9;
void dfs(int node,int l){
    level[node] = l;
    for(int i = 0 ; i < child[node].size();i++){
        parent[child[node][i]] = node; 
        dfs(child[node][i],l+1);
    }
    return;
}
void setup(int n ){
    for(int i = 1 ; i <= n ; i++){
        table[0][i] = parent[i];
    }
    for(int i = 1 ; i < lg ; i++){
        for(int j = 1 ; j <= n ; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
}
int kthancestor(int node , int k){
    for(int i = 0 ; i < lg ;i++){
        int mask = 1 << i;
        if((k&mask)){  
            node = table[i][node];
            if(node == 1) break;
        }
    }
    return node;
}
int lca(int u ,int v){
    if(level[u] > level[v]){
        swap(u,v);
    }
    int k = level[v] - level[u];
    // so we have to find the kth ancestor of the v;
    // while(level[v] != level[u]){
    //     v = parent[v];
    // } 
    // the above part can be optimised 
    v = kthancestor(v,k);
    if( u == v) return u;
    // now they both are in the same level , we have to take our steps effectively
    // so that we reach the lca with minimum cost 
    while(u != v){
        u = parent[u];
        v = parent[v];
    }
    return u;
}
int main(){
    //assuming for nodes starting from 1 
    int n;
    cin>>n;
    parent.resize(n+1);
    level.resize(n+1);
    child.resize(n+1);
    table.resize(lg,vector<int> (n+1));
    for(int i = 0 ; i < n ; i++){
        int noofchilds;
        cin>>noofchilds;
        for(int j = 0 ; j < noofchilds ; j++){
            int x ;
            cin>>x;
            child[i+1].push_back(x);
        }
    }
    parent[1] = 1;
    dfs(1,1);
    setup(n);
    int q;
    cin>>q;
    while(q--){
        int u ;
        int v;
        cin>>u>>v;
        int ans = lca(u,v);
        cout<<ans<<endl;
    }
}