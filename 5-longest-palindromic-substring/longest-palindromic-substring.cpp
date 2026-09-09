class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
                left--;
                right++;
            }
            // valid palindrome is (left+1 .. right-1)
            int len = right - left - 1;
            if (len > maxLen) {
                maxLen = len;
                start = left + 1;
            }
        };

        for (int i = 0; i < (int)s.size(); i++) {
            expand(i, i);       // odd length, center at i
            expand(i, i + 1);   // even length, center between i and i+1
        }

        return s.substr(start, maxLen);
    }
};