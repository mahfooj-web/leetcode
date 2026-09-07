class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen; // char -> last index seen
        int maxLen = 0;
        int left = 0;
        
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            
            // If c was seen before AND it's within the current window
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
                left = lastSeen[c] + 1; // move left past the duplicate
            }
            
            lastSeen[c] = right; // update last seen index
            maxLen = max(maxLen, right - left + 1);
        }
        
        return maxLen;
    }
};