/*
=========================================================
LeetCode 1614. Maximum Nesting Depth of the Parentheses
=========================================================

Problem Link:
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/

Intuition:
- The nesting depth increases whenever we encounter '('.
- The nesting depth decreases whenever we encounter ')'.
- Keep track of the current depth and continuously update
  the maximum depth reached.

Approach:
1. Initialize:
   - depth = 0 (current nesting depth)
   - maxDepth = 0 (answer)
2. Traverse the string:
   - If '(' is found:
       depth++
       maxDepth = max(maxDepth, depth)
   - If ')' is found:
       depth--
3. Return maxDepth.

Time Complexity: O(n)
Space Complexity: O(1)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxDepth = 0;

        for(char ch : s) {
            if(ch == '(') {
                depth++;
                maxDepth = max(maxDepth, depth);
            }
            else if(ch == ')') {
                depth--;
            }
        }

        return maxDepth;
    }
};