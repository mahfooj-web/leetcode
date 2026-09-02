class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        // 'slow' marks the marks the position of the last unique element found
    int slow = 0;
    // 'fast' scans through the array looking for new unique values
    for (int fast = 1; fast < nums.size(); fast++) {
        // If  current element differs from the last unique one
        // it's a new uniue value - move slow forward and place it
        if (nums[fast] != nums[slow]) {
            slow++;
            nums[slow] = nums[fast];
        }
        // If nums [fast] == nums[slow], it's a duplicate - skip it 
    }

    // slow is the index of the last  unique element,
    // so the count of unique elements is slow + 1
    return slow + 1;
    }
};