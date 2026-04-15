class Solution {
public:
    int firstOccurence(vector<int> &nums, int n, int x){
        int lo = 0, hi = n-1;
        int first = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == x){
                first = mid; hi = mid-1;
            }
            else if(nums[mid] < x){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return first;
    }
    int lastOccurence(vector<int> &nums, int n, int x){
        int lo = 0, hi = n-1;
        int last = -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] == x){
                last = mid; lo = mid+1;
            }
            else if(nums[mid] < x){
                lo = mid + 1;
            }
            else hi = mid - 1;
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOccurence(nums,n,target);
        if(first == -1) return {-1,-1};
        int last = lastOccurence(nums,n,target);
        return {first,last};
    }
};