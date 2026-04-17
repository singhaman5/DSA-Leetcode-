class Solution {
public:
    long long calculateTotalHours(vector<int> &piles, int hourly){
        long long totalHour = 0;
        for(int i = 0; i < piles.size(); i++){
            totalHour += (piles[i] + hourly - 1) / hourly;
        }
        return totalHour;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low <= high){
            int mid = low + (high - low) / 2;
            long long totalH = calculateTotalHours(piles, mid);
            if(totalH <= h) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};