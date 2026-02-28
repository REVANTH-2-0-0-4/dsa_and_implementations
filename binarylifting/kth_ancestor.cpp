#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> parent[i];
    }
    parent[1] = 1;
    const int LOG = 20;
    vector<vector<int>> table(LOG, vector<int>(n + 1));
    for (int i = 1; i <= n; i++) {
        table[0][i] = parent[i];
    }
    for (int i = 1; i < LOG; i++) {
        for (int j = 1; j <= n; j++) {
            table[i][j] = table[i - 1][ table[i - 1][j] ];
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int a, k;
        cin >> a >> k;
        for (int i = 0; i < LOG; i++) {
            if (k & (1 << i)) {
                a = table[i][a];
            }
        }
        cout << a << endl;
    }
    return 0;
}