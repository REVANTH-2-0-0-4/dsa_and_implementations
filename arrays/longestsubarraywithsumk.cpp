#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int sum = 0;
    int len = 0;
    int start = 0;
    int end = 0;
    while(end < n){
        sum+=vec[end];
        while(sum > k){
           sum-=vec[start++]; 
        }
        if(sum == k){
            len = max(len ,end - start + 1);
        }
        end++;
    }
    cout<<len<<endl;
    return 0;
}
