#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int target;
    cin >> target;
    vector<int> vec(n);
    for(int i = 0; i < n; i++){
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end());
    int start = 0;
    int end = n-1;
    bool flag = false;
    while(start < end){
        if(vec[start] + vec[end] == target){
            flag = true;
            break;
        }
        else if(vec[start] + vec[end] > target){
            end--;
        }
        else{
            start++;
        }
    }
    cout<<flag<<endl;
    return 0;
}
