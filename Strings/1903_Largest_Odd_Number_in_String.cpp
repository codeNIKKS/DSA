/*
=========================================
1903. Largest Odd Number in String
=========================================

Problem:
Given a string num representing a large integer, return the largest-valued odd integer
(as a string) that is a non-empty substring of num. If no odd integer exists, return "".

-----------------------------------------
Intuition
-----------------------------------------
An odd number must end with an odd digit (1, 3, 5, 7, 9).

To obtain the largest possible odd number:
- Find the rightmost odd digit in the string.
- Return the entire prefix ending at that digit.
- Any shorter substring ending at the same digit would have a smaller value.

-----------------------------------------
Approach
-----------------------------------------
1. Traverse the string from right to left.
2. Find the first odd digit.
3. Return the substring from index 0 to that digit.
4. If no odd digit exists, return an empty string.

-----------------------------------------
Time Complexity
-----------------------------------------
O(n)

-----------------------------------------
Space Complexity
-----------------------------------------
O(1)
(excluding the returned string)

-----------------------------------------
Key Learning
-----------------------------------------
For problems asking for the largest valid prefix:
- Identify the validity condition.
- Find the furthest position satisfying it.
- Return everything up to that position.
=========================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--) {
            if((num[i] - '0') & 1) {
                return num.substr(0, i + 1);
            }
        }

        return "";
    }
};