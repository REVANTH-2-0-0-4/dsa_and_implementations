#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n-1);
    int sum = 0;
    for(int i = 0 ; i < n -1 ; i++){
        cin>>vec[i];
        sum+=vec[i];
    }
    cout<<(n*(n+1)/2) - sum<<endl;
    return 0;
}
