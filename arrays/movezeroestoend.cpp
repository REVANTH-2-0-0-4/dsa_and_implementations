#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i =0 ; i < n ; i++){
        cin>>vec[i];
    }
    int ptr = 0;
    for(int i = 0 ; i < n ; i++){
        if(vec[i] == 0) continue;
        if(vec[i] != 0){
            swap(vec[ptr],vec[i]);
            ptr++;
        }
    }
    for(int i = 0 ; i < n ; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
