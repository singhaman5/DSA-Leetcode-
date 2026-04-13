class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> merged;
        vector<int> prev = arr[0];
        for (int i=1; i<n; i++) {
            if (arr[i][0] <= prev[1]) {
                prev[1] = max(prev[1], arr[i][1]);
            } else {
                merged.push_back(prev);
                prev = arr[i];
            }
        }
        merged.push_back(prev);
        return merged;
    }
};