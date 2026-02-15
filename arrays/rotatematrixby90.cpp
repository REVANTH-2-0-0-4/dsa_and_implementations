#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m = n;
    vector<vector<int>> vec(n, vector<int> (m));
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>vec[j][i];
        }
    }
    
    for(int i = 0 ; i < n ; i++){
        int start = 0;
        int end = m-1;
        while(start <= end){
            swap(vec[i][start],vec[i][end]);
            start++;
            end--;
        }
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<vec[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}

