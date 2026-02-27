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
int32_t main() {
    fastInputOutput();
    int n ,q;
    cin>>n>>q;
    vector<int>  next(n+1);
    vector<int> indegree(n+1,0);
    for(int i = 0 ; i < n ; i++){
        cin>>next[i+1];
        indegree[next[i+1]]++;
    }
    map<int,vector<int>> cycaccess;
    set<int> candidates;
    for(int i =1 ; i <= n ; i++){
        if(indegree[i] == 0){
            candidates.insert(i);
        }
    }
    // for(auto &in : candidates){
    //     cout<<in<<" ";
    // }
    // cout<<endl;
    int cycleid  = 1;
    vector<bool> lvisited(n+1,false);
    map<int,pair<int,int>> req;
    map<int,pair<int,int>> mp;
    for(int i = 1 ; i <= n ; i++){
        if(candidates.count(i)){
            vector<bool> localvisited(n+1,false);
            int tail = 0;
            int curr = i;
            int tot = 0;
            while(localvisited[curr] == false){
                tot++;
                localvisited[curr] = true;
                curr = next[curr]; 
            }
            int temp = i;
            while(temp != curr){
                temp = next[temp];
                tail++;
            }
            temp = i;
            int temptail = tail;
            while(temp != curr){
                req[temp] = {temptail--,tot - tail};
                temp = next[temp];
            }
            temp = curr;
            do{
                cycaccess[cycleid].push_back(temp); 
                temp = next[temp];
            }while(temp != curr);
            for(auto &in : cycaccess[cycleid]){
                cycaccess[cycleid].push_back(in);
            }
            mp[cycleid++] = {tail,tot};
        }
        else if(next[i] == i && indegree[i] ==1){
            mp[cycleid++] = {0,1};
        }
    }
    
    while(q--){
        int node , steps;
        cin>>node>>steps;


    }
    for(auto &pr : mp){
        int cycleid = pr.first;
        auto prr = pr.second;
        int tail = prr.first;
        int total = prr.second;
        cout<<" cycle id : "<<cycleid<<" tail : "<<tail<<" total : "<<total<<endl;
    }
    for(auto &pr : req){
        int node = pr.first;
        int stepstogettocycle = pr.second.first;
        int cyclelength = pr.second.second;
        cout<<"for the node : "<<node<<" ,steps to get to cycle are : "<<stepstogettocycle<<", and then the cycle length is : "<<cyclelength<<endl;
    }
    return 0;
}
