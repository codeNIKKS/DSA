/*
========================================================
PROBLEM: Aggressive Cows
========================================================

Given n stalls at different positions and k cows,
place the cows in the stalls such that the minimum
distance between any two cows is maximized.

--------------------------------------------------------
INTUITION
--------------------------------------------------------
We need to maximize the minimum distance between cows.

Instead of directly finding the answer, we binary search
on the distance.

For a given distance 'mid':
- Can we place all k cows such that every pair of
  consecutive cows is at least 'mid' apart?

If YES:
- Try a larger distance.

If NO:
- Try a smaller distance.

--------------------------------------------------------
APPROACH
--------------------------------------------------------
1. Sort the stall positions.
2. Binary search on the answer:
      low  = 1
      high = max_position - min_position
3. For every mid:
      Check if k cows can be placed.
4. If possible:
      Store the answer and move right.
5. Otherwise:
      Move left.
6. Return the largest valid distance.

--------------------------------------------------------
TIME COMPLEXITY
--------------------------------------------------------
Sorting      : O(N log N)
Binary Search: O(log(maxDist))
Placement Check: O(N)

Overall: O(N log N + N log(maxDist))

--------------------------------------------------------
SPACE COMPLEXITY
--------------------------------------------------------
O(1)
========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canweplace(vector<int>& stalls, int dist, int cows) {
        int cntcows = 1;
        int lastcow = stalls[0];

        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastcow >= dist) {
                cntcows++;
                lastcow = stalls[i];
            }

            if (cntcows >= cows) return true;
        }

        return false;
    }

    int aggressiveCows(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int low = 1;
        int high = nums.back() - nums.front();

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canweplace(nums, mid, k)) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return high;
    }
};