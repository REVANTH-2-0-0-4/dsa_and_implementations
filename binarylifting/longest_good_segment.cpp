#include <bits/stdc++.h>
using namespace std;
#define int long long
void fastInputOutput() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int lg = 20;
vector<int> startidx;
vector<vector<int>> table;
void build(int n){
    table[0] = startidx;
    for(int i = 1 ; i <= lg ; i++){
        for(int j = 0 ; j < n ; j++){
            int par = table[i-1][j];
            table[i][j] = (par == -1 ? -1 : table[i-1][par]);
        }
    }
}
int cal(int node, int k){
    int original = node;
    for(int i = 0 ; i < lg ; i++){
        if(k & (1 << i)){
            if(node == -1) break;
            node = table[i][node];
        }
    }
    return original - node;
}

int32_t main() {
    fastInputOutput();
    int T;
    cin >> T;
    while(T--) {
        int n , k , s;
        cin >> n >> k >> s;
        vector<int> vec(n);
        startidx.assign(n, -1);
        table.assign(lg+1, vector<int>(n, -1));
        for(int i = 0 ; i < n ; i++){
            cin >> vec[i];
        }
        int j = 0;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += vec[i];
            while(sum > s){
                sum -= vec[j];
                j++;
            }
            startidx[i] = j - 1;
        }
        build(n);
        int maxi = -1;
        for(int i = n - 1; i >= 0 ; i--){
            int val = cal(i, k);
            if(val != -1)
                maxi = max(maxi, val);
        }
        cout << maxi << "\n";
    }

    return 0;
}