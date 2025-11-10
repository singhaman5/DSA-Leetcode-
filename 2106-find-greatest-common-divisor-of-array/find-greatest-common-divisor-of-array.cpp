class Solution {
public:
    int gcd(int m, int n){
        if(n==0) return m;
        return gcd(n, m%n);
    }
    int findGCD(vector<int>& nums) {
        int s=INT_MAX;
        int l=INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<s) s=nums[i];
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]>l) l=nums[i];
        }
        return gcd(s,l);
    }
};