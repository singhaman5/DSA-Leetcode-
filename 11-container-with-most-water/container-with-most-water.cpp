class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxArea = 0;
        int l=0, r=n-1;
        while(l<r){
            int h = min(height[l],height[r]);
            int width = r-l;
            int area = h * width;
            maxArea = max(maxArea, area);
            if(height[l]<=height[r]) l++;
            else r--;
        }
        return maxArea;
    }
};