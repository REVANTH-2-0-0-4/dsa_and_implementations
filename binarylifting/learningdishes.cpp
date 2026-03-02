#include<bits/stdc++.h>
using namespace std;
vector<int> dishvalues;
vector<int> parent;
int find(int u , int v){
     
}
int main(){
    int n;
    cin>>n;
    dishvalues.resize(n+1);
    parent.resize(n+1);
    parent[1] = 1;
    for(int i = 1 ; i <= n ; i++){
        cin>>dishvalues[i];
    }
    for(int i = 2 ;  i <= n ; i++){
        cin>>parent[i];
    }
    int pr = 0;
    int q;
    cin>>q;
    while(q--){
        int u , v;
        cin>>u>>v;
        u^= pr;
        v^= pr;
        pr = find(u,v);
        cout<<pr<<endl;
    }

}