class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& arr) {
        // Brute Force
        int n = arr.size();
        int repeating = -1, missing = -1;
        for(int num = 1; num <= n*n; num++){
            int count = 0;
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(arr[i][j] == num){
                        count++;
                    }
                }
            }
            if(count == 2) repeating = num;
            else if(count == 0) missing = num;

            if(repeating != -1 && missing != -1){
                break;
            }
        }
        return {repeating, missing};
    }
};