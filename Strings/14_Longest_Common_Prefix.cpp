/*
    Problem: 14. Longest Common Prefix
    Link: https://leetcode.com/problems/longest-common-prefix/

    Intuition:
    The longest common prefix must be present in every string.
    Take the first string as a reference and check each character position
    across all other strings. The first mismatch marks the end of the common prefix.

    Approach (Vertical Scanning):
    1. Traverse each character index of the first string.
    2. For every index, compare that character with the corresponding
       character in all remaining strings.
    3. If a string ends or a mismatch occurs, return the prefix formed so far.
    4. If all characters of the first string match, return the entire first string.

    Time Complexity: O(N * M)
    Space Complexity: O(1)

    Where:
    N = Number of strings
    M = Length of the shortest/common prefix checked
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        for(int i = 0; i < strs[0].size(); i++) {

            for(int j = 1; j < strs.size(); j++) {

                if(i >= strs[j].size() || strs[j][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }

        return strs[0];
    }
};