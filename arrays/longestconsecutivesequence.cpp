#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    unordered_set<int> st;
    for(int i = 0 ; i < n ; i++){
         st.insert(vec[i]);
    }
    int ans = 1;
    for(int i = 0 ; i < n ; i++){
        if(st.find(vec[i]-1) == st.end()){
            int curr = vec[i];
            while(st.find(curr+1) != st.end()){
                curr++;
            }
            ans = max(ans , curr-vec[i] + 1);
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
