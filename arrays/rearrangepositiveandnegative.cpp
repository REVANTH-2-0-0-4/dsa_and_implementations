#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    int neg = 0;
    int pos = n-1;
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    vector<int> ans(n);
    for(int i = 0 ; i < n ; i++){
        if(vec[i] < 0){
            ans[neg++] = vec[i];
        }
        else{
            ans[pos--] =vec[i];
        }
    }
    cout<<"pos : "<<pos<<endl;
    pos++;
    int start = pos;
    int end = n-1;
    if( start > 0 && start < n ){
        while(start <= end){
            swap(ans[start],ans[end]);
            start++;
            end--;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
