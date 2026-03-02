#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << "[" << #x << "] = " << (x) << '\n';
#define int long long
#define all(x) x.begin(), x.end()
#define f(i, n) for (int i = 0; i < n; i++)
#define r(dt, name) for (auto &dt : name)
#define debvar(x) cerr << #x << " = " << (x) << " | ";
#define debline cerr << "Line: " << __LINE__ << "\n";
#define check(msg) cerr << "check: " << msg << " at line: " << __LINE__ << '\n';

void fastInputOutput() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int lg = 20;
vector<int> parent;
vector<vector<int>> table;
vector<int> maxdown;
vector<vector<pair<int,int>>> tree;
vector<int> level;
vector<int> nodetoroot;
void dfs(int node){
    int cost = nodetoroot[node];
    int l = level[node];
    for(auto &adj : tree[node]){
        level[adj.first] = l + 1;
        nodetoroot[adj.first] = cost + adj.second;
        dfs(adj.first);
    }
    return;
}
void build(int n){
    for(int i = 1 ; i <= n  ; i++){
        table[0][i] = parent[i];
    }
    for(int i = 1 ; i <= lg ; i++){
        for(int j = 1 ; j <= n ; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    return;
}
int lca(int a , int b){
    if(level[a] > level[b]){
        swap(a,b);
    }
    for(int i = lg; i >= 0; i--){
        if(level[table[i][b]] >= level[a]){
            b = table[i][b];
        }
    }
    if(a == b) return a;
    for(int i = lg ; i >= 0 ; i--){
        if(table[i][a] != table[i][b]){
            a = table[i][a];
            b = table[i][b];
        }
    }
    return parent[a];
}
void maxdownsetup(int node){
    if(tree[node].size() == 0) return;
    int maxi = 0;
    for(auto &adj : tree[node]){
        maxdownsetup(adj.first);
        int curr = maxdown[adj.first] + adj.second;
        maxi = max(maxi,curr);
    }
    maxdown[node] = maxi;
}
int32_t main() {
    fastInputOutput();
    int n;
    cin>>n;
    int q;
    cin>>q;
    parent.resize(n+1);
    tree.resize(n+1);
    nodetoroot.resize(n+1);
    level.resize(n+1);
    maxdown.resize(n+1);
    table.resize(lg+1, vector<int> (n+1));
    for(int i = 0; i < n -1 ; i++){
        int u , v , x;
        cin>>u>>v>>x;
        parent[v] = u;
        tree[u].push_back({v,x});
    }
    parent[1] = 1;
    level[1] = 1;
    dfs(1);
    build(n);
    maxdownsetup(1);
    while(q--){
        int  u , v , x;
        cin>>u>>v>>x;
        int lca_q = lca(u,v);
        int dist1 = nodetoroot[u] - nodetoroot[lca_q];
        int dist2 = nodetoroot[v] - nodetoroot[lca_q];
        int curr = dist1 + dist2;
        int u_maxdown = maxdown[u];
        int v_maxdown = maxdown[v];
        cout<<max(u_maxdown + v_maxdown + x , curr)<<endl;
    }

    return 0;
}