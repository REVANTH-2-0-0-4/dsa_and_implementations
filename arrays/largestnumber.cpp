#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int maxi = -1;
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
        maxi = max(maxi,vec[i]);
    }
    cout<<maxi<<endl;
    return 0;
}

