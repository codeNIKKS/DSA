/*
    LeetCode 50: Pow(x, n)

    Approach:
    ----------
    Use Binary Exponentiation (Fast Power).

    Instead of multiplying x n times, we repeatedly:
    1. If n is odd, multiply the current x with ans.
    2. Square x to move to the next power.
    3. Divide n by 2.

    Example:
    x^10 = x^2 * x^8

    The powers generated are:
    x^1 -> x^2 -> x^4 -> x^8 -> ...

    Negative exponent:
    x^(-n) = 1 / x^n

    We use long long for n because INT_MIN cannot
    be safely negated as an int.

    Time Complexity: O(log |n|)
    Space Complexity: O(1)
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;

        // Handle negative exponent
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        while (N > 0) {

            // If current exponent is odd
            if (N % 2 == 1) {
                ans *= x;
            }

            // Move to the next power
            x *= x;

            // Divide exponent by 2
            N /= 2;
        }

        return ans;
    }
};