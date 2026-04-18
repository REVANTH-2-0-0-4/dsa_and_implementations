// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
 int check(int num, int n, vector<vector<int>> &M){
    for(int i = 0; i < n; i++){
        if(i == num) continue;
        if(M[num][i] == 1 || M[i][num] == 0){
            return -1;
        }
    }
    return num;
}
    int celebrity(vector<vector<int>> &M){
        int n = M.size();
        // pick the first row , if i doest know j then j is not the celebrity 
        // if i knows the j , then i is not the celebrity 
        vector<bool> vec(n,true);
        int i = 0;
        for(int j = 0 ; j < n ; j++){
            if( i == j ) continue;
            if(M[i][j] == 0){
                // that means j is not a celebrity
                vec[j] = false; 
            }
            else{
                vec[i] = false;
                i++;
                j--;
            }
        }
        for(int i = 0 ; i < n ; i++){
            if(vec[i]) 
                return check(i,n,M);
        }
        return -1;
    }
int main() {
   int n;
   cin>>n;
   vector<vector<int>> m(n, vector<int> (n));
   for(int i = 0 ; i < n ; i++){
       for(int j = 0 ; j < n ; j++){
           cin>>m[i][j];
       }
   }
   cout<<celebrity(m)<<endl;

    return 0;
}
