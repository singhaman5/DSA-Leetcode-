class Solution {
public:
    bool vowels(char c){
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
    }
    int maxVowels(string s, int k) {
        int cnt = 0, ans = 0;
        for(int i=0; i<k; i++){
            if(vowels(s[i])) cnt++;
        }
        ans = cnt;
        for(int i=k; i<s.size(); i++){
            if(vowels(s[i])) cnt++;
            if(vowels(s[i-k])) cnt--;
            ans = max(ans,cnt);
        }
        return ans;
    }
};