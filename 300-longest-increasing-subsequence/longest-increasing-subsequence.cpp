class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        // Binary Search on LIS ->. O(n logn)
        int n = arr.size();
        vector<int> temp;
        temp.push_back(arr[0]);
        for(int i = 1; i < n; i++){  
            if(arr[i] > temp.back()){
                temp.push_back(arr[i]);
            }
            else{
                auto it = lower_bound(temp.begin(), temp.end(), arr[i]); 
                int ind = it - temp.begin();                              
                temp[ind] = arr[i];
            }
        }
        return temp.size();
    }
};