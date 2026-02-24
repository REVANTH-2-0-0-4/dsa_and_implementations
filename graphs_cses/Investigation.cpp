#include <bits/stdc++.h>
using namespace std;
#define int long long
const int INF = 1e18;
const int MOD = 1e9 + 7;
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    vector<int> dist(n + 1, INF), ways(n + 1, 0), minEdges(n + 1, INF), maxEdges(n + 1, 0);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = 0;
    ways[1] = 1;
    minEdges[1] = 0;
    maxEdges[1] = 0;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        int d = cur.first, u = cur.second;
        if (d > dist[u])
            continue;
        for (auto &e : adj[u])
        {
            int v = e.first, w = e.second;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                ways[v] = ways[u];
                minEdges[v] = minEdges[u] + 1;
                maxEdges[v] = maxEdges[u] + 1;
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w)
            {
                ways[v] = (ways[v] + ways[u]) % MOD;
                minEdges[v] = min(minEdges[v], minEdges[u] + 1);
                maxEdges[v] = max(maxEdges[v], maxEdges[u] + 1);
            }
        }
    }
    cout << dist[n] << " " << ways[n] << " " << minEdges[n] << " " << maxEdges[n] << endl;
    return 0;
}