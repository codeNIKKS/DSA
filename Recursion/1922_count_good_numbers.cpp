/*
    LeetCode 1922 - Count Good Numbers

    Approach:
    - Even indices have 5 choices: {0,2,4,6,8}
    - Odd indices have 4 choices: {2,3,5,7}
    - Number of even positions = (n + 1) / 2
    - Number of odd positions  = n / 2

    Therefore:
    answer = 5^evenPositions * 4^oddPositions

    Since n can be as large as 10^15, normal exponentiation
    is too slow. We use Binary Exponentiation to calculate
    powers in O(log n).

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/

class Solution {
public:

    long long mod = 1e9 + 7;

    long long power(long long base, long long exp) {

        long long ans = 1;

        while (exp > 0) {

            if (exp % 2 == 1) {
                ans = (ans * base) % mod;
                exp--;
            }
            else {
                base = (base * base) % mod;
                exp /= 2;
            }
        }

        return ans;
    }

    int countGoodNumbers(long long n) {

        long long evenpos = (n + 1) / 2;
        long long oddpos = n / 2;

        long long ans = power(5, evenpos) * power(4, oddpos) % mod;

        return (int)ans;
    }
};