class Solution {
public:
    bool f(int i, int j, string &s) {
        while (i < j && !isalnum(s[i])) i++;
        while (i < j && !isalnum(s[j])) j--;
        if (i >= j) return true;
        if (tolower(s[i]) != tolower(s[j])) return false;
        return f(i + 1, j - 1, s);
    }

    bool isPalindrome(string s) {
        return f(0, s.size() - 1, s);
    }
};
