class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        long long windowSum = 0;
        long long maxAns = 0;
        int n = nums.size();

        // First window
        for (int i=0; i<k; i++) {
            windowSum += nums[i];
            mp[nums[i]]++;
        }

        if (mp.size() == k) {
            maxAns = windowSum;
        }

        // Sliding window
        for (int i=k; i<n; i++) {
            // Add new element
            windowSum += nums[i];
            mp[nums[i]]++;
            // Remove old element
            windowSum -= nums[i - k];
            mp[nums[i - k]]--;
            if(mp[nums[i - k]] == 0) {
                mp.erase(nums[i - k]);
            }
            // Check if all elements are distinct
            if(mp.size() == k) {
                maxAns = max(maxAns, windowSum);
            }
        }
        return maxAns;
    }
};