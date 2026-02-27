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
vector<int> parent;
vector<int> sz;
int maxsize = 1;
int connectedcomponents;
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
void unite(int u , int v){
    int a = find(u);
    int b = find(v);
    if(a != b){
        if(sz[a] < sz[b]){
            swap(a,b);
        }
        parent[b] = a;
        sz[a] += sz[b];
        maxsize = max(maxsize, sz[a]);
        connectedcomponents--;
    }
    
}

int32_t main() {
    fastInputOutput();
    int n,m;
    cin>>n>>m;
    parent.resize(n+1);
    sz.resize(n+1,1);
     for(int i=0;i<=n;i++){
        parent[i] = i;
    }
    connectedcomponents = n;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        unite(u,v);
        cout<<connectedcomponents<<" "<<maxsize<<endl;
    }


    return 0;
}