#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);
    vector<int> indegree(n+1, 0);
    vector<int> dp(n+1, 0);
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
            dp[next] += (dp[node]%mod);
            dp[next] %= mod;
            indegree[next]--;
            if(indegree[next] == 0){
                q.push(next);
            }
        }
    }
    cout << dp[n] <<endl;
    return 0;
}