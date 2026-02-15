#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int maxi = -1;
    int curr = 0;
    for(int i = 0 ; i < n ; i++){
        if(vec[i] == 1) curr++;
        else{
            maxi = max(maxi,curr);
            curr = 0;
        }
    }
    cout<<maxi<<endl;
    
    return 0;
}
