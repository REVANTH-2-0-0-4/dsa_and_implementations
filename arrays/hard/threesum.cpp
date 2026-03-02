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
    set<vector<int>> ans;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin>>vec[i];
    }
    sort(vec.begin(),vec.end());
    for(int i = 0 ; i < n ; i++){
        if(i > 0 && vec[i] == vec[i-1]) continue;
        //fixing one element here 
        int start = i+1;
        int end = n -1;
        int target = -vec[i];
        while(start <  end){
            int sum = vec[start] + vec[end];
            if(sum < target){
                start++;
            }
            else if(sum == target){
                vector<int> temp = {vec[i] , vec[start],vec[end]};
                sort(temp.begin(),temp.end());
                ans.insert(temp);
                start++;
                end--;
            }
            else{
                end--;
            }
        }
    }
    for(auto &vec : ans){
        for(auto &el : vec){
            cout<<el<<" ";
        }
        cout<<endl;
    }

    return 0;
}