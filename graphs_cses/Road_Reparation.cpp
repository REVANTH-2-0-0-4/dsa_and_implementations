#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> parent, sz;
int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}
bool unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
    return true;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back({c, a, b});
    }
    sort(edges.begin(), edges.end());
    parent.resize(n + 1);
    sz.assign(n + 1, 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    int total = 0;
    int cnt = 0;
    for (auto &e : edges)
    {
        int c, a, b;
        tie(c, a, b) = e;
        if (unite(a, b))
        {
            total += c;
            cnt++;
        }
    }
    if (cnt != n - 1)
        cout << "IMPOSSIBLE" << endl;
    else
        cout << total << endl;
    return 0;
}