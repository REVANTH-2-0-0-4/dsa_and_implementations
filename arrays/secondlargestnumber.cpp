#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int maxi = -1;
    int secondmaxi = -1;
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
        // maxi = max(maxi,vec[i]);
        if(vec[i] >= maxi){
            secondmaxi = maxi;
            maxi = vec[i];
        }
        else if(vec[i] > secondmaxi){
            secondmaxi = vec[i];
        }
    }
    cout<<"maxi : "<<maxi<<" second maxi : "<<secondmaxi<<endl;
    return 0;
}
