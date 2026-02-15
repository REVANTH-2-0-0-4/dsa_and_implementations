#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i =0 ; i < n ; i++){
        cin>>vec[i];
    }
    int temp = vec[0];
    for(int i = 1 ; i < n ; i++){
        vec[i-1] = vec[i];
    }
    vec[n-1] = temp;
    for(int i = 0 ; i < n ; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
