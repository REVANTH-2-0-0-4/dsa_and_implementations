class Solution {
public:
    long long subArrayRanges(vector<int>& vec) {
        int n = vec.size();
        vector<int> nexts(n, n), nextg(n, n), prevs(n, -1), prevg(n, -1);
        stack<int> st;

        // next smaller (strictly)
        for (int i = 0; i < n; i++) {
            int num = vec[i];
            while (!st.empty() && vec[st.top()] > num) {
                nexts[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // prev smaller (strictly)
        for (int i = n - 1; i >= 0; i--) {
            int num = vec[i];
            while (!st.empty() && vec[st.top()] >= num) {
                prevs[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // next greater (strictly)
        for (int i = 0; i < n; i++) {
            int num = vec[i];
            while (!st.empty() && vec[st.top()] < num) {
                nextg[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while (!st.empty()) st.pop();

        // prev greater (strictly)
        for (int i = n - 1; i >= 0; i--) {
            int num = vec[i];
            while (!st.empty() && vec[st.top()] <= num) {
                prevg[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            long long maxc = (i - prevg[i]) * 1LL * (nextg[i] - i);
            long long minc = (i - prevs[i]) * 1LL * (nexts[i] - i);
            ans += vec[i] * (maxc - minc);
        }
        return ans;
    }
};
