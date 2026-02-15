#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int>> vec(n, vector<int> (m));
    int temp = 0;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cin>>vec[i][j];
            if(vec[i][j] == 0){
                 if(i != 0) vec[i][0] = 0;
                 else if( i == 0) temp = 1;
                  vec[0][j] = 0;
            }
        }
    }
    for(int i = 1 ; i < n ; i++){
        for(int j = 1; j < m; j++){
            if(vec[i][0] == 0 || vec[0][j] == 0){
                vec[i][j] = 0;
            }
        } 
    }
    for(int i = 0 ; i < n ; i++){
        if(vec[0][0] == 0){
            vec[i][0] = 0;
        }
    }
    if(temp){
        for(int i = 0 ; i < m ; i++){
            vec[0][i] = 0; 
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
