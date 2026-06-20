/*
===============================================================================
LeetCode 242. Valid Anagram
===============================================================================

Problem:
Given two strings s and t, return true if t is an anagram of s,
and false otherwise.

-------------------------------------------------------------------------------
Brute Force Approach: Sort Both Strings
-------------------------------------------------------------------------------

Intuition:
Two strings are anagrams if they contain exactly the same characters with the
same frequencies.

If we sort both strings, all identical characters will be grouped together.
If the sorted strings become equal, then they are anagrams.

Example:
s = "anagram"
t = "nagaram"

After sorting:
s = "aaagmnr"
t = "aaagmnr"

Both strings are equal, so return true.

-------------------------------------------------------------------------------
Algorithm:
1. If lengths are different, return false.
2. Sort string s.
3. Sort string t.
4. Compare both sorted strings.
5. Return true if equal, otherwise false.

-------------------------------------------------------------------------------
Time Complexity: O(n log n)
Space Complexity: O(1)
===============================================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};


/*
===============================================================================
LeetCode 242. Valid Anagram
===============================================================================

Problem:
Given two strings s and t, return true if t is an anagram of s,
and false otherwise.

-------------------------------------------------------------------------------
Better Approach: Hash Map Frequency Counting
-------------------------------------------------------------------------------

Intuition:
If two strings are anagrams, every character must appear the same number
of times in both strings.

Count the frequency of each character in string s using a hash map.
Then traverse string t and decrease the frequency.

If any character frequency becomes negative, or a character is missing,
the strings cannot be anagrams.

-------------------------------------------------------------------------------
Algorithm:
1. If lengths are different, return false.
2. Create an unordered_map to store character frequencies.
3. Traverse s and increment frequency of each character.
4. Traverse t and decrement frequency of each character.
5. If any frequency becomes negative, return false.
6. If traversal completes successfully, return true.

-------------------------------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(k)
where k = number of distinct characters.
===============================================================================
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        for (char ch : t) {
            freq[ch]--;

            if (freq[ch] < 0) {
                return false;
            }
        }

        return true;
    }
};


/*
===============================================================================
LeetCode 242. Valid Anagram
===============================================================================

Problem:
Given two strings s and t, return true if t is an anagram of s,
and false otherwise.

-------------------------------------------------------------------------------
Optimal Approach: Frequency Array (Lowercase English Letters)
-------------------------------------------------------------------------------

Intuition:
Since the problem states that the strings contain only lowercase English
letters, we can replace the hash map with a fixed-size frequency array of
size 26.

Store the count of each character from string s and decrease the count while
traversing string t.

If all frequencies become zero, both strings contain exactly the same
characters with the same frequencies.

-------------------------------------------------------------------------------
Algorithm:
1. If lengths are different, return false.
2. Create a frequency array of size 26 initialized with 0.
3. Traverse string s and increment frequency of each character.
4. Traverse string t and decrement frequency of each character.
5. Check the frequency array:
   - If any value is non-zero, return false.
6. Return true.

-------------------------------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(1)

Reason:
The frequency array size is fixed (26) and does not depend on input size.
===============================================================================
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        vector<int> freq(26, 0);

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        for (char ch : t) {
            freq[ch - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) return false;
        }

        return true;
    }
};