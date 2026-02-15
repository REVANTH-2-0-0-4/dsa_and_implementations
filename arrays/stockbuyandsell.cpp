#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int mini = vec[0];
    int maxi = 0;
    for(int i = 0 ; i < n ; i++){
        maxi = max(maxi,vec[i] - mini);
        mini = min(mini,vec[i]);
    }
    cout<<maxi<<endl;
    return 0;
}
