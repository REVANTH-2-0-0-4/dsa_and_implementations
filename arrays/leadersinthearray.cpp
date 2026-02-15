#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    deque<int> dq;
    int maxi = -1;
    for(int i = n - 1 ; i >= 0 ; i--){
        if(vec[i] > maxi){
            dq.push_front(vec[i]);
        }
        maxi = max(maxi,vec[i]);
    }
    for(int i = 0 ; i < dq.size(); i++){
        cout<<dq[i]<<" ";
    }
    cout<<endl;
    return 0;
}

