class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map to store:  value-> index (number we've already see )
        unordered_map<int, int> seen;

        for (int  i = 0; i < nums.size(); i++) {
            // Calculate what number we need to reach the target
            int complement = target - nums[i];

            // Check  if we've already seen the complement
            if (seen.find(complement) != seen.end()) {
                // Found it! Return the earlier index and current index
                return {seen[complement], i};
            }
            // Store current number and its for future looups
            seen[nums[i]] = i;
        }

        // No solution found(per problem constraints, this shouldn't happen)
        return {};
    }
};

// time: O(n) - single pass through the array
// space:O(n) - hash map can store up to n elements