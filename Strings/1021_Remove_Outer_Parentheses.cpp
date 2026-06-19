/*
=========================================================
1021. Remove Outermost Parentheses
=========================================================

Problem Link:
https://leetcode.com/problems/remove-outermost-parentheses/

---------------------------------------------------------
Intuition
---------------------------------------------------------
A primitive valid parentheses string always starts with an
outer '(' and ends with its matching ')'.

If we keep track of the current nesting depth:
- The first '(' of a primitive appears when depth changes
  from 0 -> 1, so we skip it.
- The last ')' of a primitive appears when depth changes
  from 1 -> 0, so we skip it.
- All other parentheses belong to the inner part and are
  added to the answer.

---------------------------------------------------------
Approach
---------------------------------------------------------
1. Maintain a counter 'depth'.
2. For every '(':
      - If depth > 0, add it to answer.
      - Increment depth.
3. For every ')':
      - Decrement depth.
      - If depth > 0, add it to answer.
4. Return the constructed string.

---------------------------------------------------------
Time Complexity
---------------------------------------------------------
O(n)

---------------------------------------------------------
Space Complexity
---------------------------------------------------------
O(n)
(for the output string)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string ans;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) ans += ch;
                depth++;
            } 
            else {
                depth--;
                if (depth > 0) ans += ch;
            }
        }

        return ans;
    }
};