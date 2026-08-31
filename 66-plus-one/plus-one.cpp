class Solution {
public: 
    vector<int> plusOne(vector<int>& digits) {
        // loop through the digits array from the last index to the first(right to left)
        // because addition (and carrying) starts from the least significant digit
        for (int i = digits.size() - 1; i >= 0; i--) { // Case 1: current digit is less than 9, so adding 1 cause NO carry
            if(digits[i] < 9) {
                digits[i]++;
            return digits;
             // no carry to propagate, so we're done return immediately
            }
            // Case 2: current digit is 9. adding 1 make it 10,
            // which means this digit becomes 0 and we carry 1 over to the next digit
            digits[i] = 0;
        }
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
    