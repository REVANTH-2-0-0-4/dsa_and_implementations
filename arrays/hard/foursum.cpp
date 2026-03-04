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

    vector<vector<int>> fourSum(vector<int>& vec, int tot) {
        int n = vec.size();
         set<vector<int>> st;
        sort(vec.begin(),vec.end());
         for(int i = 0 ; i < n ; i++){
                if(i > 0 && vec[i] == vec[i-1]) continue;
                for(int j = i + 1 ; j < n ; j++){
                   if(j > i + 1 && vec[j] == vec[j-1]) continue;
                        int start = j + 1;
                        int end = n-1;
                        while(start < end){
                            int sum = vec[start] + vec[end];
                            int target = tot-(vec[i] + vec[j]);
                            if(sum == target){
                                vector<int> temp = { vec[i],vec[j],vec[start],vec[end]};
                                sort(temp.begin(),temp.end());
                                st.insert(temp);
                                start++;
                                end--;
                            }
                            else if(sum < target){
                                start++;
                            }
                            else{
                                end--;
                            }
                        }
                }
         }
          vector<vector<int>> ans;
          for(auto &el : st){
            ans.push_back(el);
          }
          return ans;
    }
void fastInputOutput() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int32_t main() {
    fastInputOutput();
    int T = 1;
    cin >> T;
    while(T--) {

    }
    return 0;
}