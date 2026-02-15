#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int maxi = -1;
    int idx = -1;
    for(int i = n -1 ; i >= 0 ; i--){
      if(vec[i] < maxi){
          idx = i;
          break;
      }    
        maxi = max(maxi,vec[i]);
    }
    if(idx != -1){
        for(int i = n-1 ; i >= idx  ; i--){
        if(vec[i] > vec[idx]){
            swap(vec[i],vec[idx]);
            break;
        }
    }
    }
    int start = idx+1;
    int end = n-1;
   
        while(start <= end){
            swap(vec[start],vec[end]);
            start++;
            end--;
        }

    for(int i = 0 ; i < n ; i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
