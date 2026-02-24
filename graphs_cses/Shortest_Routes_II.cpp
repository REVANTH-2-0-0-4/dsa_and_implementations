// #include <bits/stdc++.h>
// using namespace std;
// void fastInputOutput() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
// }
// int32_t main() {
//     fastInputOutput();
//     int n, m, q;
//     cin >> n >> m >> q;
//     vector<vector<long long>> dist(n, vector<long long>(n, LLONG_MAX));
//     for (int i = 0; i < n; i++) {
//         dist[i][i] = 0;
//     }
//     for (int i = 0; i < m; i++) {
//         int u, v;
//         long long w;
//         cin >> u >> v >> w;
//         u--; v--;
//         dist[u][v] = min(dist[u][v], w);
//         dist[v][u] = min(dist[v][u], w);
//     }
//     for (int k = 0; k < n; k++) {
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < n; j++) {
//                 if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX) {
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
//     }
//     for (int i = 0; i < q; i++) {
//         int u, v;
//         cin >> u >> v;
//         u--; v--;
//         if (dist[u][v] == LLONG_MAX) {
//             cout << -1 << "\n";
//         } else {
//             cout << dist[u][v] << "\n";
//         }
//     }
//     return 0;
// }
/*
 * Shortest Routes II
 * C++14
 * Floyd-Warshall Algorithm
 */
