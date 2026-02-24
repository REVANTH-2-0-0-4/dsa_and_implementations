#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin>>n;
// enter the row  for which you want
// ncr --> n!/(r!*(n-r)!)  eg 5c2 -- 5*4/2!
vector<int> ans;
int num = n;
int den = 1;
ans.push_back(1);
int curr = 1;
for(int c = 1 ; c <= n ; c++){
   curr*= num;
   curr /= den;
   ans.push_back(curr);
   num--;
   den++;
}
for(int i = 0 ; i < ans.size();i++){
    cout<<ans[i]<<" ";
}
// cout<<ans<<endl;
    return 0;
}
