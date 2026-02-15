#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int candidate = -1;
    int cnt = 0;
    for(int i =0 ; i < n ; i++){
        if(cnt == 0){
            candidate = vec[i];
            cnt = 1;
            continue;
        }
        if(vec[i] == candidate){
            cnt++;
        }
        else if(candidate != vec[i]){
            cnt--;
        }
    }
    cout<<candidate<<endl;
    cout<<cnt<<endl;
    return 0;
}
