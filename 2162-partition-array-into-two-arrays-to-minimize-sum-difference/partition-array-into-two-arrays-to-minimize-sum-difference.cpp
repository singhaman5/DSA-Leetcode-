class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int half = n / 2;
        vector<int> left(nums.begin(), nums.begin() + half);
        vector<int> right(nums.begin() + half, nums.end());
        vector<vector<int>> sumL(half + 1), sumR(half + 1);

        // generate subset sums for left half
        for (int mask = 0; mask < (1 << half); mask++) {
            int cnt = 0, sum = 0;
            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += left[i];
                }
            }
            sumL[cnt].push_back(sum);
        }

        // generate subset sums for right half
        for (int mask = 0; mask < (1 << half); mask++) {
            int cnt = 0, sum = 0;
            for (int i = 0; i < half; i++) {
                if (mask & (1 << i)) {
                    cnt++;
                    sum += right[i];
                }
            }
            sumR[cnt].push_back(sum);
        }
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;
        for (int i = 0; i <= half; i++) {
            sort(sumR[i].begin(), sumR[i].end());
        }
        for (int i = 0; i <= half; i++) {
            for (int s1 : sumL[i]) {
                int need = totalSum / 2 - s1;
                auto &vec = sumR[half - i];
                auto it = lower_bound(vec.begin(), vec.end(), need);
                if (it != vec.end())
                    ans = min(ans, abs(totalSum - 2 * (s1 + *it)));
                if (it != vec.begin())
                    ans = min(ans, abs(totalSum - 2 * (s1 + *prev(it))));
            }
        }
        return ans;
    }
};