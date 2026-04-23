class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n, 0);
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &p : mp){
            auto &v = p.second;
            int m = v.size();
            long long sum = 0;
            for(int i = 0; i < m; i++) sum += v[i];
            long long leftSum = 0;
            for(int i = 0; i < m; i++){
                sum -= v[i];
                ans[v[i]] = (long long)i * v[i] - leftSum + sum - (long long)(m - i - 1) * v[i];
                leftSum += v[i];
            }
        }
        return ans;
    }
};