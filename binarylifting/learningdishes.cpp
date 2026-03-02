#include<bits/stdc++.h>
using namespace std;
vector<int> values;
vector<int> parent;
vector<vector<int>> table;
const int lg = 20;
vector<pair<int,int>> vec;
vector<vector<int>> childs;
int find(int node , int weight){   
    int curr = node; 
    for(int i = lg ; i >= 0 ; i--){
        if(vec[table[i][node]].first > weight){
            node = table[i][node];
        }       
    }
    node = parent[node];
    return vec[curr].second - vec[node].second;
}
void dfs(int node ,int max , int count){
    if(values[node] > max){
        max = values[node];
        count++;
    }
    vec[node] = {max,count};
    for(auto &child : childs[node]){
        dfs(child , max,count);
    }
}
void build(int n){
    table[0] = parent;
    for(int i = 1 ; i <= lg ; i++){
        for(int j = 1 ; j <= n ; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    values.resize(n+1);
    parent.resize(n+1);
    vec.resize(n+1);
    table.resize(lg+1,vector<int> (n+1));
    parent[1] = 0;
    vec[0] = {-2e9,0};
    childs.resize(n+1);
    for(int i = 1 ; i <= n ; i++){
      cin>>values[i];
    }
    for(int i = 2 ;  i <= n ; i++){
        cin>>parent[i];
        childs[parent[i]].push_back(i);
    }
    dfs(1,0,0);
    build(n);
    int pr = 0;
    int q;
    cin>>q;
    while(q--){
        int u , v;
        cin>>u>>v;
        u^= pr;
        v^= pr;
        if(vec[u].first <= v) pr = 0;
        else pr = find(u,v);
        cout<<pr<<"\n";
    }

}