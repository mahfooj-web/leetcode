class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;         // pool of available digits
        vector<int> factorial(n + 1, 1);

        // Precompute factorials: factorial[i] = i!
        for (int i = 1; i <= n; i++) {
            factorial[i] = factorial[i - 1] * i;
            nums.push_back(i);    // nums = [1, 2, 3, ..., n]
        }

        k--;  // convert k to 0-indexed (easier for math below)

        string result = "";

        // Build the answer one digit at a time, from left to right
        for (int i = n; i >= 1; i--) {
            // (i-1)! = number of permutations possible for the
            // remaining (i-1) digits after we fix one digit here
            int block = factorial[i - 1];

            // Which "block" of permutations does k fall into?
            // That block index tells us which digit (by position
            // in nums[]) goes in this spot
            int index = k / block;

            // Place that digit in the result and remove it from
            // the pool so it can't be reused
            result += to_string(nums[index]);
            nums.erase(nums.begin() + index);

            // Reduce k to be the remainder within the chosen block —
            // now we solve the same problem one digit smaller
            k %= block;
        }

        return result;
    }
};