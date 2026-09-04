class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
      int n = nums.size();
        
        // suff_min[i] will store the minimum value in nums from index i to n - 1
        vector<int> suff_min(n);
        int current_min = INT_MAX;
        for (int i = n - 1; i >= 0; --i) {
            current_min = min(current_min, nums[i]);
            suff_min[i] = current_min;
        }
        
        // Track the maximum value in nums from index 0 to i
        int current_max = INT_MIN;
        for (int i = 0; i < n; ++i) {
            current_max = max(current_max, nums[i]);
            // Check instability score: prefix_max(0..i) - suffix_min(i..n-1) <= k
            if (current_max - suff_min[i] <= k) {
                return i;
            }
        }
        
        return -1;
    }
};  