class Solution {
public:
    int trap(vector<int>& height) {
     int n = height.size();
     vector<int> maxright(n,-1);
     vector<int> maxleft(n,-1);
     int currmaxi = -1;
     for(int i = 0; i < n ; i++){
        currmaxi = max(currmaxi,height[i]);
        maxleft[i] = currmaxi; 
     }   
     currmaxi = -1;
     for(int i = n - 1 ; i >= 0 ; i--){
        currmaxi = max(currmaxi,height[i]);
        maxright[i] = currmaxi;
     }
     int ans = 0;
     for(int i = 0 ; i < n ; i++){
        ans+= max(0,(min(maxright[i],maxleft[i])-height[i]));
     }
     return ans;
    }
};
