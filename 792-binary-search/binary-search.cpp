class Solution {
public:
    // Binary Search Using Recursion -:
    int binary(vector<int> &nums, int left, int right, int target){
        if(left>right) return -1;
        int mid = left+(right-left)/2;
        if(nums[mid]==target){
            return mid;
        }
        if(target<nums[mid]){
            return binary(nums,left,mid-1,target);
        }
        return binary(nums,mid+1,right,target);
    }
    int search(vector<int>& nums, int target) {
        return binary(nums,0,nums.size()-1,target);
    }
};