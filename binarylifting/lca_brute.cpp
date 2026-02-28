#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;
vector<int> parent;
vector<int> level;
vector<vector<int>> child;
void dfs(int node,int l){
    level[node] = l;
    for(int i = 0 ; i < child[node].size();i++){
        parent[child[node][i]] = node; 
        dfs(child[node][i],l+1);
    }
    return;
}
int lca(int u ,int v){
    if(level[u] > level[v]){
        swap(u,v);
    }
    while(level[v] != level[u]){
        v = parent[v];
    }
    if( u == v) return u;
    while(u != v){
        u = parent[u];
        v = parent[v];
    }
    return u;
}
int main(){
    //assuming
    int n;
    cin>>n;
    parent.resize(n+1);
    level.resize(n+1);
    child.resize(n+1);
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