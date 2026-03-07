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
vector<vector<int>> adj;
vector<vector<int>> adj2;
vector<int> ans;
vector<int> visited;
vector<int> topoorder;
void fastInputOutput() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
stack<int> st;
void toposort(int node){
    visited[node] = true;
    for(auto &el : adj[node]){
        if(!visited[el]) toposort(el);
    }
    st.push(node);
}
void dfs(int node){
    visited[node] = true;
    for(auto &el : adj2[node]){
        if(!visited[el]){
            dfs(el);
        }
    }
    return;
}
int32_t main() {
    fastInputOutput();
    int n;
    cin>>n;
    int m;
    cin>>m;
    adj.resize(n+1);
    adj2.resize(n+1);
    visited.resize(n+1);
    for(int i = 0 ; i < m ; i++){
        int x , y;
        cin>>x>>y;
        adj[x].push_back(y);
    }
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]){
            toposort(i);
        }
    }
    // cout<<"toposort : ";
    while(!st.empty()){
        int node = st.top();
        st.pop();
        topoorder.push_back(node);
        // cout<<node<<" ";
    }
    // cout<<endl;
    for(int i = 1 ; i <= n ; i++){
        for(auto &el : adj[i]){
            adj2[el].push_back(i);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        visited[i] = false;
    }
    int scc = 0;
    for(auto &node : topoorder){
        if(!visited[node]){
            scc++;
            ans.push_back(node);
            dfs(node);
        }
    }
    // cout<<scc<<endl;
    if(ans.size() == 1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
        cout<<ans[1]<<" "<<ans[0]<<endl;
    }
    return 0;
}