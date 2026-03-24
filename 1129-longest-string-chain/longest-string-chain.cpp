class Solution {
public:
    bool isPredecessor(string &s1, string &s2){
        if(s2.size() != s1.size() + 1) return false;
        int i = 0, j = 0;
        while(j < s2.size()){
            if(i < s1.size() && s1[i] == s2[j]){
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == s1.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });
        int n = words.size();
        vector<int> dp(n, 1);
        int maxi = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(isPredecessor(words[j], words[i])){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};