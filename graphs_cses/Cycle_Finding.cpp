#include<bits/stdc++.h>
using namespace std;
#define int long long

struct edge {
    int start;
    int end;
    int cost;
};

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<edge> edges;
    vector<int> parent(n + 1, -1);
    
    for(int i = 0 ; i < m ; i++){
        int start, end, cost;
        cin >> start >> end >> cost;
        edges.push_back({start, end, cost});
    }
    
    vector<int> dist(n + 1, 0); // to detect neg cycles in case of disconnected graph, we can initialize dist with 0 instead of inf
    for(int i = 0 ; i < n - 1 ; i++){
        for(auto &edge : edges){
            if(dist[edge.start] + edge.cost < dist[edge.end]){
                dist[edge.end] = dist[edge.start] + edge.cost;
                parent[edge.end] = edge.start; 
            }
        }
    }
    
    bool flag = false;
    int currnode = -1;
    
    for(auto &edge : edges){
        if(dist[edge.start] + edge.cost < dist[edge.end]){
            flag = true;
            currnode = edge.end;
            dist[edge.end] = dist[edge.start] + edge.cost;
            parent[edge.end] = edge.start;
        }
    }
    if(flag){
        cout << "YES\n";
        vector<int> cycle;
        // to stay in the cycle
        for(int i = 0 ; i < n - 1 ; i++){
            currnode = parent[currnode];
        }
        int temp = currnode;
        do {
            cycle.push_back(temp);
            temp = parent[temp];
        } while(temp != currnode);
        cycle.push_back(temp);
        reverse(cycle.begin(), cycle.end());
        for(auto &node : cycle){
            cout << node << " ";
        }
        cout << "\n";
    }
    else {
        cout << "NO\n";
    }
    
    return 0;
}