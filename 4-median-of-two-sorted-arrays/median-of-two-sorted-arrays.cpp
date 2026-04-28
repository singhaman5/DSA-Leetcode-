class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        int i = 0, j = 0;
        int n = nums1.size();
        int m = nums2.size();
        while(i < n && j < m) {
            if(nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        while(i < n) {
            merged.push_back(nums1[i]);
            i++;
        }
        while(j < m) {
            merged.push_back(nums2[j]);
            j++;
        }
        int size = merged.size();
        if(size % 2 == 1) {
            return merged[size / 2];
        }
        return (merged[size / 2 - 1] + merged[size / 2]) / 2.0;
    }
};