/*
=========================================================
LeetCode 205. Isomorphic Strings
=========================================================

Problem Link:
https://leetcode.com/problems/isomorphic-strings/

Approach: Brute Force
---------------------
For every character in string s, check all previous characters.

1. If s[i] has appeared before, then the corresponding
   character in t must be the same.
2. If s[i] has not appeared before, ensure that t[i]
   has not already been mapped by some other character.

This directly validates the isomorphic property without
using any extra hash maps.

Time Complexity: O(n²)
Space Complexity: O(1)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            bool found = false;

            for (int j = 0; j < i; j++) {

                if (s[j] == s[i]) {
                    if (t[j] != t[i]) {
                        return false;
                    }
                    found = true;
                    break;
                }

                if (t[j] == t[i] && s[j] != s[i]) {
                    return false;
                }
            }
        }

        return true;
    }
};


/*
=========================================================
LeetCode 205. Isomorphic Strings
=========================================================

Problem Link:
https://leetcode.com/problems/isomorphic-strings/

Approach: Better (Using Hash Map + Set)
---------------------------------------
Maintain a mapping from characters of s to characters of t.

1. If a character from s is already mapped,
   verify that it maps to the current character in t.
2. If it is not mapped, ensure the current character
   of t is not already mapped by another character.
3. Store the new mapping.

Using a hash map avoids repeatedly scanning previous
characters and reduces the time complexity to O(n).

Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_set<char> used;

        for (int i = 0; i < s.size(); i++) {

            if (mp.find(s[i]) != mp.end()) {
                if (mp[s[i]] != t[i]) {
                    return false;
                }
            }
            else {
                if (used.count(t[i])) {
                    return false;
                }

                mp[s[i]] = t[i];
                used.insert(t[i]);
            }
        }

        return true;
    }
};


/*
=========================================================
LeetCode 205. Isomorphic Strings
=========================================================

Problem Link:
https://leetcode.com/problems/isomorphic-strings/

Approach: Optimal (Two Arrays)
------------------------------
Use two arrays of size 256 to store the last seen
index of characters in both strings.

For every position i:

1. If the last seen index of s[i] and t[i]
   are different, the mapping is inconsistent.
2. Otherwise, update both arrays with the
   current index.

This works because isomorphic strings must have
identical character occurrence patterns.

Example:
s = "egg"
t = "add"

Index: 0 1 2
s    : e g g
t    : a d d

Both strings repeat characters at the same positions,
so they are isomorphic.

Time Complexity: O(n)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> sIndex(256, -1);
        vector<int> tIndex(256, -1);

        for (int i = 0; i < s.size(); i++) {

            if (sIndex[s[i]] != tIndex[t[i]]) {
                return false;
            }

            sIndex[s[i]] = i;
            tIndex[t[i]] = i;
        }

        return true;
    }
};