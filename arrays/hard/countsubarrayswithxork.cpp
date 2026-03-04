#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int xr = 0;
    int ans = 0;
    unordered_map<int,int> mp;
    mp[0] = 1;
    for(int i = 0 ; i < n ; i++){
        xr ^= vec[i];
        if(mp.find(xr^k) != mp.end()){
            ans += i - mp[xr^k];
        }
        mp[xr]++;
    }
    cout<<ans<<endl;
    return 0;
}
