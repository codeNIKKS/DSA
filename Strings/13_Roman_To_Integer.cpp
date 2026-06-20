/*
========================================================
LeetCode 13. Roman to Integer
========================================================

Problem:
Convert a Roman numeral string into its corresponding integer value.

--------------------------------------------------------
Intuition
--------------------------------------------------------
Roman numerals are usually written from left to right in
decreasing order of value.

However, when a smaller numeral appears before a larger
numeral, it represents subtraction:

IV = 4
IX = 9
XL = 40
XC = 90
CD = 400
CM = 900

While traversing the string:
- If current value < next value, subtract it.
- Otherwise, add it.

--------------------------------------------------------
Approach
--------------------------------------------------------
1. Store Roman numeral values in a hashmap.
2. Traverse the string from left to right.
3. Compare current symbol with the next symbol.
4. If current value is smaller than next value:
      subtract current value.
   Else:
      add current value.
5. Return the final answer.

--------------------------------------------------------
Time Complexity
--------------------------------------------------------
O(n)

--------------------------------------------------------
Space Complexity
--------------------------------------------------------
O(1)
(Only 7 Roman symbols are stored.)

--------------------------------------------------------
Example
--------------------------------------------------------
Input:  "MCMXCIV"

M  -> +1000
C  -> -100
M  -> +1000
X  -> -10
C  -> +100
I  -> -1
V  -> +5

Output: 1994
========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100},
            {'D', 500}, {'M', 1000}
        };

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && mp[s[i]] < mp[s[i + 1]]) {
                ans -= mp[s[i]];
            } else {
                ans += mp[s[i]];
            }
        }

        return ans;
    }
};