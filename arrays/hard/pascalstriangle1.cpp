#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> ans;
    vector<int> prev = {1};
    ans.push_back(prev);
    while(n--){
        vector<int> temp;
        temp.push_back(prev[0]);
        for(int i = 1 ; i <  prev.size();i++){
            temp.push_back(prev[i]+prev[i-1]);
        }
        temp.push_back(prev[prev.size()-1]);
        ans.push_back(temp);
        prev = temp;
    }
    int cnt = 1;
    for(auto &vec : ans){
        cout<<" row - "<<cnt<<" --> ";
        for(auto &in : vec){
            cout<<in<<" ";
        }
        cout<<endl;
        cnt++;
    }
    return 0;
}
