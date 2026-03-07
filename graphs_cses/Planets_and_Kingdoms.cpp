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
vector<vector<int>> adj2;
vector<vector<int>> adj;
vector<int> topoorder;
vector<int> visited;
int scc = 0;
void toposort(int node){
    visited[node] = true;
    for(auto &el : adj[node]){
        if(!visited[el]){
            toposort(el);
        }
    }
    topoorder.push_back(node);
}
void dfs(int node){
    visited[node] = scc;
    for(auto &el : adj2[node]){
        if(visited[el] == 0){
            dfs(el);
        }
    }
}
int32_t main() {
    fastInputOutput();
    int n;
    cin>>n;
    int m;
    cin>>m;
    adj.resize(n+1);
    visited.resize(n+1);
    adj2.resize(n+1);
    for(int i = 1 ; i <= m ; i++){
        int x , y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            toposort(i);
        }
    }
    reverse(topoorder.begin(),topoorder.end());
    // for(auto &el : topoorder){
    //     cout<<el<<" ";
    // }
    // cout<<endl;
    for(int i = 1 ; i <= n ; i++){
        for(auto &el : adj[i]){
            //  cout<<"processed"<<endl;
            adj2[el].push_back(i);
        }
    }
    for(int i = 1; i <= n ; i++){
        visited[i]  = 0;
    }
    // for(int i = 1; i <= n ; i++){
    //     cout<<visited[i]<<" ";
    // }
    // cout<<endl;
    for(auto &node : topoorder){
        if(visited[node] == 0){
            // cout<<" processed"<<endl;
            scc++;
            dfs(node);
        }
    }
    cout<<scc<<endl;
    for(int i =1 ; i <= n ; i++){
        cout<<visited[i]<<" ";
      }
      cout<<endl;

    return 0;
}