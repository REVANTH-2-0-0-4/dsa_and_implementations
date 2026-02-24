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
vector<bool> visited;
vector<int> parent;
vector<bool> pathvisited;
vector<int> ans;
vector<vector<pair<int,int>>> adj;
bool dfs(int node){
    cout<<"visiting node "<<node<<endl;
    if(ans.size() >= 3){
        return true;
    }
    if(node == 2){
        cout<<"node is 2"<<endl;
    }
    for(auto &adjnode : adj[node]){
        if(ans.size() >= 3){
            return true;
        }
        if(node == 2){
             cout<<" checking :"<<adjnode.first<<endl;
        }
        if(!visited[adjnode.first]){
            pathvisited[adjnode.first] = 1;
            visited[adjnode.first] = 1;
            parent[adjnode.first] = node;
            if(dfs(adjnode.first)){
                return true;
            }   
            pathvisited[adjnode.first] = 0;
        }
        else if(pathvisited[adjnode.first]){
            cout<<"cycle found"<<endl;
            vector<int> cycle;
            int currnode = adjnode.first;
            parent[adjnode.first] = node;
            do{
                cycle.push_back(currnode);
                currnode = parent[currnode];
            }while(currnode != adjnode.first);
            cycle.push_back(adjnode.first);
            if(ans.size() >= 3){
                ans = cycle;
                return true;
            }
        }
    }
    return false;
}
int32_t main() {
    fastInputOutput();
    int n ,m;
    cin>>n>>m;
    adj.resize(n+1);
    for(int i = 0 ; i < m ; i++){
        int u , v , cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    visited.resize(n+1,0);
    parent.resize(n+1,-1);
    pathvisited.resize(n+1,0);
    bool flag = false;
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            pathvisited[i] = 1;
            visited[i] = 1;
            flag |= dfs(i);
            pathvisited[i] = 0;
        }
    }
    if(flag){
        cout<<ans.size()<<endl;
        for(auto &x : ans){
            cout<<x<<" ";
        }
        cout<<endl;
    }
    else{
        cout<<-1<<endl;
    }
    return 0;
}