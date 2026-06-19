/*
=========================================================
151. Reverse Words in a String
=========================================================

Problem Link:
https://leetcode.com/problems/reverse-words-in-a-string/

Intuition:
- Reverse the entire string.
- Each word now appears in reverse order.
- Extract every word, reverse it back, and append it to
  the answer.
- Ignore multiple spaces and maintain only one space
  between words.

Approach:
1. Reverse the complete string.
2. Traverse the reversed string.
3. Extract each word until a space is encountered.
4. Reverse the extracted word.
5. Append it to the answer with a single space.
6. Return the final string without the leading space.

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();

        reverse(s.begin(), s.end());

        string ans = "";

        for (int i = 0; i < n; i++) {
            string word = "";

            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            reverse(word.begin(), word.end());

            if (word.length() > 0) {
                ans += " " + word;
            }
        }

        return ans.substr(1);
    }
};