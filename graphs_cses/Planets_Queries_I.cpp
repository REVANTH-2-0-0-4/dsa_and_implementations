// use binary lifing , since it is a funcitonal graph 
// the  equation of this question , --> a number can be broken down to the powers of two 
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()
#define f(i, n) for (int i = 0; i < n; i++)
void fastInputOutput() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}
const int lg = 30;  
vector<vector<int>> table;
int32_t main() {
    fastInputOutput();
    int n, q;
    cin >> n >> q;
    table.resize(lg + 1, vector<int>(n + 1));
    for(int i = 1; i <= n; i++){
        cin >> table[0][i];
    }
    for(int i = 1; i <= lg; i++){
        for(int j = 1; j <= n; j++){
            table[i][j] = table[i-1][ table[i-1][j] ];
        }
    }
    while(q--){
        int x, k;
        cin >> x >> k;
        for(int i = 0; i <= lg; i++){
            if(k & (1LL << i)){
                x = table[i][x];
            }
        }
        cout << x <<endl;
    }

    return 0;
}