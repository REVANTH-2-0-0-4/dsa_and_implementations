#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debline cerr << "Line: " << __LINE__ << "\n";
int32_t main(){
    int n , m , k;
    cin>>n>>m>>k;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i = 0 ; i < m ; i++){
        int u , v , cost;
        cin>>u>>v>>cost;
        adj[u].push_back({v,cost});
    }
    vector<int> cnt(n+1);
    vector<multiset<int>> dist(n+1);
    for(int i = 2; i <= n ; i++){
        for(int j = 0 ; j < k ; j++){
            dist[i].insert(LLONG_MAX);
        }
    }
    dist[1].insert(0);
    for(int i = 1; i < k ; i++){
        dist[1].insert(LLONG_MAX);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    while(!pq.empty()){
        auto pr = pq.top();
        int cost = pr.first;
        int node = pr.second;
        // cout<<node<<endl;
        pq.pop();
        if(cost > *dist[node].rbegin()){
            continue;
        }
        if(cnt[node] == k){
            continue;
        }
        cnt[node]++;
        for(auto &adjnode : adj[node]){
            int newcost = cost + adjnode.second;
            int adjnodeindex = adjnode.first;
            if(newcost < *dist[adjnodeindex].rbegin()){
                // cout<<"pushing "<<adjnodeindex<<" with node "<<node<<endl;
                // cout<<"before for node "<<adjnodeindex<<" size is "<<dist[adjnodeindex].size()<<endl;
               auto it = prev(dist[adjnodeindex].end());
                dist[adjnodeindex].erase(it);
                dist[adjnodeindex].insert(newcost);
                // cout<<"after for node "<<adjnodeindex<<" size is "<<dist[adjnodeindex].size()<<endl;
                pq.push({newcost, adjnodeindex});
            }
        }
    }
    // cout<<dist[n].size()<<endl;
    for(auto &x : dist[n]){
        cout << x << " ";
    }
    cout<<endl;
    return 0;
}