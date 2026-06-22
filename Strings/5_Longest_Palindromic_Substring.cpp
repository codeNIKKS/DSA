/*
    Problem: 5. Longest Palindromic Substring
    Link: https://leetcode.com/problems/longest-palindromic-substring/

    Intuition:
    Generate every possible substring and check whether it is a palindrome.
    If a substring is palindrome and its length is greater than the current
    longest palindrome, update the answer.

    Approach:
    1. Use two loops to generate all substrings s[i...j].
    2. For each substring, check if it is a palindrome using two pointers.
    3. If palindrome and longer than current answer, update answer.
    4. Return the longest palindrome found.

    Time Complexity: O(n^3)
    Space Complexity: O(1)

    Note:
    We avoid creating new substrings during palindrome checking.
    Instead, we directly check the original string using indices.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {

        while(l < r) {
            if(s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    string longestPalindrome(string s) {

        int n = s.length();

        int start = 0;
        int maxLen = 1;

        for(int i = 0; i < n; i++) {

            for(int j = i; j < n; j++) {

                if(isPalindrome(s, i, j)) {

                    int len = j - i + 1;

                    if(len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};


/*
    Problem: 5. Longest Palindromic Substring
    Link: https://leetcode.com/problems/longest-palindromic-substring/

    Intuition:
    Every palindrome has a center.

    For odd-length palindromes, the center is a character itself.
    Example: "racecar" -> center = 'e'

    For even-length palindromes, the center lies between two characters.
    Example: "abba" -> center between the two 'b's

    Instead of generating all substrings, treat every index as a possible
    center and expand outward while the characters match.

    Approach:
    1. Iterate through every index i.
    2. Expand around (i, i) to find odd-length palindromes.
    3. Expand around (i, i + 1) to find even-length palindromes.
    4. Track the starting index and maximum palindrome length.
    5. Return the longest palindrome substring.

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

class Solution {
public:

    void expand(string &s, int l, int r, int &start, int &maxLen) {

        int n = s.length();

        while(l >= 0 && r < n && s[l] == s[r]) {
            l--;
            r++;
        }

        int len = r - l - 1;

        if(len > maxLen) {
            maxLen = len;
            start = l + 1;
        }
    }

    string longestPalindrome(string s) {

        int start = 0;
        int maxLen = 0;

        for(int i = 0; i < s.length(); i++) {

            // Odd-length palindrome
            expand(s, i, i, start, maxLen);

            // Even-length palindrome
            expand(s, i, i + 1, start, maxLen);
        }

        return s.substr(start, maxLen);
    }
};