#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i = 0 ; i < n ; i++){
        cin>>vec[i];
    }
    int startidx = -1;
    int endidx = -1;
    int miniidx = -1;
    int curr = 0;
        int maxi = -1e9;
        int mini = 0;
        // int n = vec.size();
        for(int i = 0 ; i < n ; i++){
            curr+=vec[i];
            if( curr - mini > maxi ){
                maxi = curr - mini;
                startidx = miniidx + 1;
                endidx = i;
            }
            if(curr < mini){
                mini = curr;
                miniidx = i;
            }
        }
        cout<<" the subarray with max sum starts from the idx : "<<startidx<<" and ends at : "<<endidx<<endl;
    return 0;
}
