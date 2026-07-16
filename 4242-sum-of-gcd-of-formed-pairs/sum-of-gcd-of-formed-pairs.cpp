class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,0);
        int maxi = 0;
        for(int i=0; i<n; i++){
            maxi = max(maxi, nums[i]);
            pre[i] = gcd(nums[i],maxi);
        }
        sort(pre.begin(), pre.end());
        int l=0, r=n-1;
        long long ans = 0;
        while(l<r){
            ans += gcd(pre[l],pre[r]);
            l++;
            r--;
        }
        return ans;
    }
};