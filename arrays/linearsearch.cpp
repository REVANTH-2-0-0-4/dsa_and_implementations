#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   int target;
   cin>>target;
   vector<int> vec(n);
   bool flag = false;
   for(int i = 0 ; i < n ; i++){
       cin>>vec[i];
       if(vec[i] == target){
           flag = true;
       }
   }
   cout<<flag<<endl;
    return 0;
}
