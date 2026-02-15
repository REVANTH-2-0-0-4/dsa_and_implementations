#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int xorr = 0;
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
        xorr^= vec[i];
    }
    cout<<xorr<<endl;
    return 0;
}
