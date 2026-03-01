// you are given n followed by two arrays , the first containing the parent of each node 
// the second array says that there are n cats , which will start the process one by one , cats[i] == initial position which it want to go 
// and then in each process the cat sees its parent , if its unoccupied then it will occupy it. in that way it will jump to root
// we have to store the count for each process
#include<iostream>
#include<set>
#include<vector>
#include<map>
using namespace std;
const int lg = 20;
vector<int> parent;
vector<vector<int>> table;
vector<bool> visited;
void setup(int n){
    for(int i = 1 ; i <= n ; i++){
        table[0][i] = parent[i];
    }
    for(int i = 1 ; i < lg ; i++){
        for(int j = 1 ; j <= n ; j++){
            table[i][j] = table[i-1][table[i-1][j]];
        }
    }
    return;
}
int process(int pos){
    if(visited[pos] == true) return 0;
    cout<<" visited for node "<<pos<<endl;
    int stepcnt = 0;
    for(int i = lg  - 1; i >= 0 ; i--){
        // cout<<" entered the loop : "<<endl;
        if(visited[table[i][pos]] == false){
            pos = table[i][pos];
            stepcnt+= ( 1 << i);
        }
    }
   visited[pos] = true;
   return ++stepcnt;
}
int main(){
    int n;
    cin>>n;
    parent.resize(n+1);
    table.resize(lg,vector<int> (n+1));
    visited.resize(n+1,false);
    vector<int> ans(n+1);
    vector<int> cats(n+1);
    int finans = 0;
    for(int i = 1 ; i <= n ; i++){
        cin>>parent[i];
    }
    for(int i = 1 ; i <= n ; i++){
        cin>>cats[i];
    }
    parent[1] = 0;
    visited[0] = true;
    setup(n);
    // cout<<"visited here "<<endl;
    for(int i = 1 ; i<= n ; i++){
       int temp = process(cats[i]);
        ans[i] = temp;
        finans+= temp;
    }
    for(int i = 1 ; i <= n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<" final answer : "<<finans<<endl;
}