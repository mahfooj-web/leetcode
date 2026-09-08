class Solution {
public:
    int reverse(int x) {
        long result = 0;  // use long to safely detect overflow before casting back to int

        while (x != 0) {
            int digit = x % 10;   // extract the last digit
                                   // (works correctly for negative x too, e.g. -123 % 10 = -3)
            x /= 10;               // remove the last digit from x

            result = result * 10 + digit;  // append digit to the result

            // Check overflow AFTER building result, using the long's extra range
            if (result > INT_MAX || result < INT_MIN) {
                return 0;
            }
        }

        return static_cast<int>(result);
    }
};