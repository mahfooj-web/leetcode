class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res; // stores all unique triplets
        int n = nums.size(); // store as int to avoid unsigned underflow in n - 2

        //step1:   sort so we can use two pointers and group duplicates together
        sort(nums.begin(), nums.end());

        // Step 2: fix the first element of the triplet
        // (i stops at n - 3 because we need two more elements after it)
        for (int i = 0; i < n - 2; i++) {

            // Optimization: if the smallest number is  > 0, every sum will be > 0, every sum will be > 0
            if (nums[i] > 0) break;

            // Skip duplicate first elements to avoid duplicate triplets
            // (compare with the PREVIOUS element, not the next one)
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // Step 3: two pointers on the remaining part of the array
            int left = i + 1; // smallest candidate for the second number
            int right = n - 1; // largest candidate for the thirs=d number

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    // Sum too small: need a bigger number, so move left foreward
                    left++;
                } else if (sum > 0) {
                    // Sum too big; need a smaller number, so move right backward
                    right--;
                } else {
                    // Found a valid triplet
                    res.push_back({nums[i], nums[left], nums[right]});

                    // Move both pointers inward to look for new pairs
                    left++;
                    right--;

                    // Skip duplicate second elements
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return res;
        
    }
};
// Why sort + two pointers is the preferred choice:-
// sorting costs only O(n log n), which is dominated by the O(n^2) loop.
// two pointers replace the inner loop's O(n) search with a single linear scan, which removes one full factor of n compared  to n compared to brute force.
// sorted order make duplicates skipping trivial, avoiding a set<vector<int>>

// time:- O(n^2) Sorting is O(n log n) and loop with two pointers is  O(n) per i
// Space:- O(1) extra, ignoring the output and the sort's internal space.