class Solution {
public:
    bool equalProduct(int idx, long long p1, long long p2, long long target, vector<int>& nums){
        if(p1>target || p2>target) return false;
        if(p1==target && p2==target && idx==nums.size()) return true;
        if(idx==nums.size()) return false;
        bool a=equalProduct(idx+1, p1*nums[idx], p2,target,nums);
        bool b=equalProduct(idx+1, p1, p2*nums[idx], target,nums);
        return a|b;
    }
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        return equalProduct(0,1,1,target,nums);
    }
};