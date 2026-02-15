#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    map<int,int> mp;
    int sum = 0;
    int cnt = 0;
    mp[0] = 1;
    for(int i = 0 ; i < n ; i++){
        sum+=vec[i];
        if(mp.find(sum - k) != mp.end()){
            cnt+= mp[sum-k];
        }        
        mp[sum]++;
    }
    cout<<cnt<<endl;
    return 0;
}
