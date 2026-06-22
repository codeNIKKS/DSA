/*
=========================================================
LeetCode 1781. Sum of Beauty of All Substrings
=========================================================

Problem:
The beauty of a string is defined as the difference between
the frequency of the most frequent character and the least
frequent character (excluding characters that do not appear).

Return the sum of beauty values of all possible substrings.

---------------------------------------------------------
Intuition:
For every starting index, expand the substring one character
at a time while maintaining character frequencies.

For each substring:
1. Find the maximum frequency.
2. Find the minimum non-zero frequency.
3. Beauty = maxFreq - minFreq.
4. Add it to the final answer.

Since the string contains only lowercase English letters,
we can use a frequency array of size 26.

---------------------------------------------------------
Approach:
1. Fix a starting index 'i'.
2. Create a frequency array of size 26.
3. Extend the substring using index 'j'.
4. Update frequency of s[j].
5. Scan the 26 frequencies to find:
      - maximum frequency
      - minimum non-zero frequency
6. Add (maxFreq - minFreq) to answer.
7. Repeat for all starting indices.

---------------------------------------------------------
Time Complexity:
O(n² × 26) ≈ O(n²)

Space Complexity:
O(26) ≈ O(1)

---------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            vector<int> freq(26, 0);

            for(int j = i; j < n; j++) {

                freq[s[j] - 'a']++;

                int maxfreq = 0;
                int leastfreq = INT_MAX;

                for(int count : freq) {
                    if(count > 0) {
                        maxfreq = max(maxfreq, count);
                        leastfreq = min(leastfreq, count);
                    }
                }

                ans += (maxfreq - leastfreq);
            }
        }

        return ans;
    }
};