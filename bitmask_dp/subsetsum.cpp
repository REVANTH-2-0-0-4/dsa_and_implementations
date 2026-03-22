#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int k ;
    cin>>k;
     
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int ans = 0;
    int max_mask = 1 << n ;
    for(int mask = 0 ; mask < max_mask; mask++){
        int sum = 0;
        for(int pos = 0 ; pos < n ; pos++){
            if(mask & ( 1 << pos)){
                sum += vec[pos];
            }
        }
        if(sum >= k) ans++;
    }
    cout<<ans<<endl;
    return 0;
}

// time complexity of this approach is 2^n * n 