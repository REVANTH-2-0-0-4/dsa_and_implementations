#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    int len = 0;
    unordered_map<int,int> mp;
    int curr = 0;
    mp[0] = -1;
    for(int i = 0; i < n; i++){
        curr += vec[i];
        if(mp.find(curr - k) != mp.end()){
            len = max(len, i - mp[curr - k]);
        }
        if(mp.find(curr) == mp.end()){
            mp[curr] = i;
        }
    }
    cout << len << endl;
    return 0;
}
