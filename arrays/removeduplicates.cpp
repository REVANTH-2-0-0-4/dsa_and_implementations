#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i =0 ; i < n ; i++){
        cin>>vec[i];
    }
    int run = 0;
    for(int i = 1 ; i < n ; i++){
        if(vec[i] != vec[run]){
            run++;
            swap(vec[i],vec[run]);
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
