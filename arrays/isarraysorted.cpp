#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
   bool flag = true;
   for(int i = 0 ; i < n ; i++){
       cin>>vec[i];
   }
   for(int i = 1 ; i < n ; i++){
       if(vec[i] < vec[i-1]){
           flag = false;
           break;
       }
   }
   cout<<flag<<endl;
    return 0;
}
