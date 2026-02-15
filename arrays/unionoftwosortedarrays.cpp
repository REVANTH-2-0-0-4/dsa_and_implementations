#include<bits/stdc++.h>
using namespace std;
int main(){
   int a;
   int b;
   cin>>a>>b;
   vector<int> aa(a);
   vector<int> bb(b);
   for(int i = 0 ; i < a ; i++){
       cin>>aa[i];
   }
   aa.push_back(1e9);
   bb.push_back(1e9);
   for(int j = 0 ; j < b ; j++){
       cin>>bb[j];
   }
//   a++;
//   b++;
   int aptr = 0;
   int bptr = 0;
   vector<int> vec;
   while (aptr < a && bptr < b){
      if(aa[aptr] <= bb[bptr]){
          vec.push_back(aa[aptr]);
          aptr++;
      }
      else{
          vec.push_back(bb[bptr]);
          bptr++;
      }
   }
   while(aptr < a){
       vec.push_back(aa[aptr++]);
   }
   while(bptr < b){
       vec.push_back(bb[bptr++]);
   }
   for(int i = 0 ; i < vec.size();i++){
       cout<<vec[i]<<" ";
   }
   cout<<endl;
    return 0;
}
