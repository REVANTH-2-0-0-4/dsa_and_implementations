#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> vec(n, vector<int> (m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>vec[i][j];
        }
    }
    vector<int> ans;

        int left = 0, right = m-1;
        int top = 0, bottom = n-1;

        while(left <= right && top <= bottom){

            for(int i = left; i <= right; i++)
                ans.push_back(vec[top][i]);
            top++;

            for(int i = top; i <= bottom; i++)
                ans.push_back(vec[i][right]);
            right--;

            if(top <= bottom){
                for(int i = right; i >= left; i--)
                    ans.push_back(vec[bottom][i]);
                bottom--;
            }

            if(left <= right){
                for(int i = bottom; i >= top; i--)
                    ans.push_back(vec[i][left]);
                left++;
            }
        }
       for(int i = 0 ; i < ans.size();i++){
           cout<<ans[i]<<" ";
       }
       cout<<endl;
    return 0;
}
