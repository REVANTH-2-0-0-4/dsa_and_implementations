#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int curr = 0;
        int maxi = -1e9;
        int mini = 0;
        int n = vec.size();
        for(int i = 0 ; i < n ; i++){
            curr+=vec[i];
            maxi = max(maxi,curr-mini);
            mini = min(mini,curr);
        }
    return 0;
}
