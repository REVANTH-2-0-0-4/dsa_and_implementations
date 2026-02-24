#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> dp(n+1, -1);
    vector<int> pre(n+1, -1);
    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    dp[1] = 1; 
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &next : adj[node]){
            if(dp[node] != -1 && dp[node] + 1 > dp[next]){
                dp[next] = dp[node] + 1;
                pre[next] = node;
            }
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    if(dp[n] == -1){
        cout << "IMPOSSIBLE\n";
        return 0;
    }
    cout << dp[n] << "\n";
    vector<int> path;
    int node = n;
    while(node != -1){
        path.push_back(node);
        node = pre[node];
    }
    reverse(path.begin(), path.end());
    for(auto x : path){
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}