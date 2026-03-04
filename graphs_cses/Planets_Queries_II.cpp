#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> from;
vector<int> depth;
vector<int> cycleid;
vector<int> parent;
vector<int> indegree;
vector<int> candidates;
map<int,int> noofelementsincycle;
vector<int> stepstostartnodeincycle;
vector<int> visited;
int currcycleid = 0;
int n, queries;
vector<vector<int>> up;
int LOG;
int advance(int node, int k) {
    for(int i = 0; i <= LOG; i++) {
        if(k & (1 << i)) {
            node = up[node][i];
        }
    }
    return node;
}
void bfs(vector<int> &cyclenodes){
    queue<pair<int,int>> q;
    for(auto &node : cyclenodes){
        q.push({node,0});
        depth[node] = 0;
    }
    while(!q.empty()){
        auto pr = q.front();
        q.pop();                          
        int node = pr.first;
        int dep = pr.second;              
        for(auto &el : from[node]){
            if(depth[el] == -1){
                depth[el] = dep + 1;
                cycleid[el] = cycleid[node]; 
                q.push({el, dep + 1});
            }
        }
    }
}

void dfs(int node){
    while(!visited[node]){
        visited[node] = 1;
        node = parent[node];
    }
    int cyclestartnode = node;
    if(visited[cyclestartnode] == 1 && cycleid[cyclestartnode] == -1){
        cycleid[cyclestartnode] = ++currcycleid;
        int cnt = 0;
        int curr = cyclestartnode;
        vector<int> cyclenodes;
        do{
            cnt++;
            stepstostartnodeincycle[curr] = cnt;
            cycleid[curr] = currcycleid;
            cyclenodes.push_back(curr);
            curr = parent[curr];
        }while(curr != cyclestartnode);
        
        noofelementsincycle[currcycleid] = cnt;
        curr = cyclestartnode;
        do{
            stepstostartnodeincycle[curr] = cnt - stepstostartnodeincycle[curr] + 1;
            curr = parent[curr];
        }while(curr != cyclestartnode);
        
        bfs(cyclenodes);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> queries;
    parent.resize(n+1);
    from.resize(n+1);
    cycleid.resize(n+1, -1);
    indegree.resize(n+1, 0);
    depth.resize(n+1, -1);                         
    stepstostartnodeincycle.resize(n+1);
    visited.resize(n+1, 0);
    LOG = ceil(log2(n));
    up.assign(n + 1, vector<int>(LOG + 1, 0));
    for(int i = 1 ; i <= n ; i++){
        cin >> parent[i];
        up[i][0] = parent[i]; 
        indegree[parent[i]]++;
        from[parent[i]].push_back(i);
    }
    for(int j = 1; j <= LOG; j++) {
        for(int i = 1; i <= n; i++) {
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(indegree[i] == 0){
            candidates.push_back(i);
        }
    }
    for(auto &candidate : candidates){
        if(!visited[candidate]) {
            dfs(candidate);
        }
    }
    for(int i = 1 ; i <= n ; i++){
        if(!visited[i]) {
            dfs(i);
        }
    }
    while(queries--) {
        int a, b;
        cin >> a >> b;
        if(cycleid[a] != cycleid[b] || cycleid[a] == -1) {
            cout << -1 << endl;
            continue;
        }
        if(depth[a] < depth[b]) {
            cout << -1 << endl;
            continue;
        }
        int diff = depth[a] - depth[b];
        int ancestor = advance(a, diff);
        if(depth[b] > 0) {
            if(ancestor == b) cout << diff << endl;
            else cout << -1 << endl;
        } else {
            int len = noofelementsincycle[cycleid[a]];
            int dist = (stepstostartnodeincycle[ancestor] - stepstostartnodeincycle[b] + len) % len;
            cout << diff + dist << endl;
        }
    }
    return 0;
}