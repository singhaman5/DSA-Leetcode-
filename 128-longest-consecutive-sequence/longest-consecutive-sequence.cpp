class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end());
        int lastSmaller = INT_MIN, cnt = 0, longest = 0;
        for(int i=0; i<n; i++){
            if(nums[i] -1 == lastSmaller){
                cnt += 1;
                lastSmaller = nums[i];
            }
            else if(lastSmaller != nums[i]){
                cnt = 1;
                lastSmaller = nums[i];
            }
            longest = max(longest,cnt);
        }
        return longest;
    }
};