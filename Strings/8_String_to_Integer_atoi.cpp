/*
=========================================================
LeetCode 8. String to Integer (atoi)
=========================================================

Problem:
Convert a string to a 32-bit signed integer following
the atoi() rules:
1. Ignore leading whitespaces.
2. Determine the sign (+ or -).
3. Read digits until a non-digit character appears.
4. Clamp the result within the 32-bit signed integer range.

Intuition:
We process the string from left to right.
- Skip leading spaces.
- Check for an optional sign.
- Build the number digit by digit.
- Before adding a new digit, check whether it would
  cause overflow.
- Return the final signed value.

Approach:
1. Skip leading whitespaces.
2. Determine sign (+1 or -1).
3. Traverse consecutive digits.
4. Before inserting a digit:
      num = num * 10 + digit
   check if it exceeds INT_MAX.
5. If overflow occurs:
      return INT_MAX (positive)
      return INT_MIN (negative)
6. Return sign * num.

Time Complexity: O(n)
Space Complexity: O(1)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.size();

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Determine sign
        int sign = 1;

        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        long long num = 0;

        // Read digits
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Overflow check
            if (num > INT_MAX / 10 ||
                (num == INT_MAX / 10 && digit > 7)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            num = num * 10 + digit;
            i++;
        }

        return sign * num;
    }
};