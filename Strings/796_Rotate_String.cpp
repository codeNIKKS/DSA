/*
=========================================================
LeetCode 796. Rotate String
Approach: Brute Force (Generate Every Rotation)
=========================================================

Intuition:
- A left rotation at index i can be represented as:
      s.substr(i) + s.substr(0, i)
- Generate all possible rotations of s and compare each
  with goal.
- If any rotation matches goal, return true.

Example:
s = "abcde"

i = 0 -> "abcde"
i = 1 -> "bcdea"
i = 2 -> "cdeab"
i = 3 -> "deabc"
i = 4 -> "eabcd"

If any generated string equals goal, return true.

Time Complexity: O(n²)
- n rotations
- Each rotation construction/comparison takes O(n)

Space Complexity: O(n)
- Temporary rotated string is created

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) {

        int n = s.length();

        if(n != goal.length())
            return false;

        for(int i = 0; i < n; i++) {

            string firstPart = s.substr(i);
            string secondPart = s.substr(0, i);

            string rotated = firstPart + secondPart;

            if(rotated == goal)
                return true;
        }

        return false;
    }
};


/*
=========================================================
LeetCode 796. Rotate String
Approach: Better (Rotate String Repeatedly)
=========================================================

Intuition:
- Instead of generating every rotation from scratch,
  perform one left rotation at a time.
- After each rotation, compare the current string with goal.
- If they become equal at any point, return true.

Example:
s = "abcde"

After 1 rotation -> "bcdea"
After 2 rotations -> "cdeab"
After 3 rotations -> "deabc"
After 4 rotations -> "eabcd"
After 5 rotations -> "abcde"

If any rotation equals goal, return true.

Time Complexity: O(n²)
- rotate() takes O(n)
- Performed n times

Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length())
            return false;

        if(s == goal)
            return true;

        int n = s.length();

        for(int i = 0; i < n; i++) {

            rotate(s.begin(), s.begin() + 1, s.end());

            if(s == goal)
                return true;
        }

        return false;
    }
};


/*
=========================================================
LeetCode 796. Rotate String
Approach: Optimal (String Doubling + Substring Search)
=========================================================

Intuition:
- If goal is a valid rotation of s, then it must appear
  as a substring inside (s + s).
- Concatenating s with itself contains all possible
  rotations of s as contiguous substrings.

Example:
s = "abcde"

s + s = "abcdeabcde"

Possible rotations:
abcde
bcdea
cdeab
deabc
eabcd

All of them appear inside "abcdeabcde".

Therefore, if goal exists in (s + s), it is a valid
rotation of s.

---------------------------------------------------------
Algorithm:
1. If lengths are different, return false.
2. Create doubled = s + s.
3. Check if goal is present in doubled using find().
4. If found, return true; otherwise return false.

---------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)

=========================================================
*/

class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.length() != goal.length())
            return false;

        string doubled = s + s;

        return doubled.find(goal) != string::npos;
    }
};