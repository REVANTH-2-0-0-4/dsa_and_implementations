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

vector<vector<int>> g;
vector<vector<int>> gr;
vector<int> vis;
vector<int> order;
vector<int> comp;

void dfs1(int node){
    vis[node] = 1;
    for(auto &to : g[node]){
        if(!vis[to]) dfs1(to);
    }
    order.push_back(node);
}

void dfs2(int node,int id){
    comp[node] = id;
    for(auto &to : gr[node]){
        if(comp[to] == -1) dfs2(to,id);
    }
}

int32_t main() {
    fastInputOutput();

    int n,m;
    cin>>n>>m;

    g.resize(2*m);
    gr.resize(2*m);

    vector<vector<pair<int,char>>> nodechoices(n+1);

    for(int i = 1 ; i <= n ; i++){
        for(int j = 0 ; j < 2 ; j++){
            char c;
            int toppling;
            cin>>c>>toppling;
            nodechoices[i].push_back({toppling,c});
        }
    }

    for(int i = 1 ; i <= n ; i++){
        auto a = nodechoices[i][0];
        auto b = nodechoices[i][1];
        int u = 2*(a.first-1) + (a.second == '+' ? 0 : 1);
        int v = 2*(b.first-1) + (b.second == '+' ? 0 : 1);
        int nu = u ^ 1;
        int nv = v ^ 1;
        g[nu].push_back(v);
        g[nv].push_back(u);
        gr[v].push_back(nu);
        gr[u].push_back(nv);
    }

    vis.assign(2*m,0);

    for(int i = 0 ; i < 2*m ; i++){
        if(!vis[i]) dfs1(i);
    }
    comp.assign(2*m,-1);
    for(auto& el : order){
        cout<<el<<" ";
    }
    cout<<endl;
    reverse(all(order));
    int id = 0;
    for(auto &node : order){
        if(comp[node] == -1){
            dfs2(node,id++);
        }
    }
    vector<char> ans(m+1);
    for(int i = 1 ; i <= m ; i++){
        int p = 2*(i-1);
        int n1 = p^1;
        if(comp[p] == comp[n1]){
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
        if(comp[p] > comp[n1]) ans[i] = '+'; // to avoid contradictions 
        else ans[i] = '-';
    }
    for(int i = 1 ; i <= m ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
}