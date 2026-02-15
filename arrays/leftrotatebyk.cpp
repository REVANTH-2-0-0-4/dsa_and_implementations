#include<bits/stdc++.h>
using namespace std;
void reverse(vector<int> &vec, int start ,int end){
    while(start <= end){
        swap(vec[start],vec[end]);
        start++;
        end--;
    }
    return;
}
// 1 , 2 , 3 , 4, 5 ,6 ,7, 8, 9 , 10 , 11 , 12 ,13 ,14 ,15
int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    vector<int> vec(n);
    for(int i =0 ; i < n ; i++){
        cin>>vec[i];
    }
    
    k%=n;
    bool flag = true;
    if( k == 0){
        flag = false;
    }
    if(flag){
    reverse(vec,0,k-1);
    reverse(vec,k, n-1);
    reverse(vec,0,n-1);
    }
    for(int i = 0 ; i < n ; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}
