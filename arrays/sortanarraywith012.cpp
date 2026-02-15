#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
       int start = 0;
       int end = n-1;
       for(int i = 0 ; i < n ; i++){
         while(vec[i] == 0 && i > start){
            swap(vec[i],vec[start]);
            start++;
         }
         while(vec[i] == 2 && end > i){
            swap(vec[i],vec[end]);
            end--;
         }
         while(vec[i] == 0 && i > start){
            swap(vec[i],vec[start]);
            start++;
         }
         while(vec[i] == 2 && end > i){
            swap(vec[i],vec[end]);
            end--;
         }
       }
    for(int i = 0 ; i < n ; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
