#include <bits/stdc++.h>
using namespace std;

// PROBLEM:
// Valid Palindrome



// OPTIMAL APPROACH
// Use two pointers from start and end.
// Ignore non-alphanumeric characters.
// Compare lowercase characters while moving inward.
//
// TC: O(n)
// SC: O(1)

class Solution {
public:
    bool isPalindrome(string s) {

        int start = 0;
        int end = s.size() - 1;

        while(start <= end) {

            if(!isalnum(s[start])) {
                start++;
                continue;
            }

            if(!isalnum(s[end])) {
                end--;
                continue;
            }

            if(tolower(s[start]) != tolower(s[end])) {
                return false;
            }

            start++;
            end--;
        }

        return true;
    }
};