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
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
       long long  cand1 = 1e10;
    long long cand2 = 1e10;
    int cnt1 = 0;
    int cnt2 = 0;
    for(int i = 0 ; i < n ; i++){
        if(cnt1 == 0 && vec[i] != cand2){
            cand1 = vec[i];
            cnt1 = 1;
        }
        else if(cnt2 == 0 && vec[i] != cand1){
            cand2 = vec[i];
            cnt2 = 1;
        }
        else if(vec[i] == cand1){
            cnt1++;
        }
        else if(vec[i] == cand2){
            cnt2++;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(int i = 0 ; i < n ; i++){
        if(vec[i] == cand1) cnt1++;
        if(vec[i] == cand2) cnt2++;
    }
    vector<int> ans;
    if(cnt1 > n/3){
        ans.push_back(cand1);
    }
    if(cnt2 > n/3){
        ans.push_back(cand2);
    }
    if(ans.size() == 0){
        cout<<" there are no elements , whose frequency is greater than n/3"<<endl;
    }
    else{
        for(auto &cand : ans){
        cout<<cand<<" ";
        }
        cout<<endl;
    }
    return 0;
}