#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        int u , v, cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;
    vector<int> dist(n+1,LLONG_MAX);
    dist[1] = 0ll;
    pq.push({0ll,1});
    while(!pq.empty()){
        auto pr = pq.top();
        int cost = pr.first;
        int node = pr.second;
        pq.pop();
        if(cost > dist[node]) continue;
        for(auto &neighbour : adj[node]){
            if(cost + neighbour.second  < dist[neighbour.first]){
                dist[neighbour.first] = cost + neighbour.second;
                pq.push({dist[neighbour.first],neighbour.first});
            }
        }
    }
    for(int i =1 ; i <= n ; i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}