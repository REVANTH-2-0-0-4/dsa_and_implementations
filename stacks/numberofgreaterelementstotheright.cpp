class Solution {
public:
    void merge(int start , int mid , int end , vector<pair<int,int>> &vop , vector<int> &ans){
        int i  = start ;
        int j = mid + 1;
        vector<pair<int,int>> temp;
        while( i <= mid && j <= end){
            if(vop[i].first < vop[j].first){
                ans[vop[i].second] += (end - j + 1);
                temp.push_back(vop[i++]);
            }
            else{
                temp.push_back(vop[j++]);
            }
        }
        while(i <= mid){
            temp.push_back(vop[i++]);
        }
        while(j <= end){
            temp.push_back(vop[j++]);
        }
        int idx = start;
        for(int i = 0 ; i < temp.size();i++){
            vop[i+idx] = temp[i];
        }
    }
    void mergesort(int start , int end , vector<pair<int ,int>> &vop , vector<int> &ans){
        if( start >= end){
            return;
        }
        int mid = start + (end - start)/2;
        mergesort(start,mid,vop,ans);
        mergesort(mid+1,end,vop,ans);
        merge(start,mid,end,vop,ans);        
    }
    vector<int> count_NGE(vector<int> &arr, vector<int> &indices) {
       int n = arr.size();
       vector<int> ans(n,0);
       vector<pair<int,int>> vop;
       for(int i = 0 ; i < n ; i++){
         vop.push_back({arr[i],i});
       }
       mergesort(0,n-1,vop,ans);
       vector<int> res;
       for(auto &idx : indices){
        res.push_back(ans[idx]);
       }
       return res;
    }
};
