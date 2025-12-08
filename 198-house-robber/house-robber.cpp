class Solution {
public:
    int rob(vector<int>& nums) {
        int prev1 = 0;  // max money till previous house
        int prev2 = 0;  // max money till the house before previous
        for (int num : nums) {
            int take = prev2 + num;   // rob this house
            int skip = prev1;         // skip this house
            int curr = max(take, skip);
            prev2 = prev1;   // move forward
            prev1 = curr;
        }
        return prev1;
    }
};
