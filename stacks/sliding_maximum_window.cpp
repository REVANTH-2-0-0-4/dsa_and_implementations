#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;
        int i = 0;
        for(int j = 0 ; j < n ; j++){
            while(!dq.empty()&& nums[dq.back()] < nums[j]){
                dq.pop_back();
            }
            dq.push_back(j);
            if(j - i + 1 == k){
                ans.push_back(nums[dq[0]]);
                i++;
                while(!dq.empty() && dq[0] < i){
                    dq.pop_front();
                }
            }
        }
        return ans;
    }
};
