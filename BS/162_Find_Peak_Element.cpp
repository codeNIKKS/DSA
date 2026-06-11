/*
-----------------------------------------------------------
Problem: 162. Find Peak Element
Link: https://leetcode.com/problems/find-peak-element/

Approach: Brute Force (Linear Scan)

Intuition:
A peak element is greater than its adjacent elements.
For every index, check:
1. Left neighbor is smaller (or doesn't exist).
2. Right neighbor is smaller (or doesn't exist).

The first index satisfying both conditions is a valid peak.

Algorithm:
1. Traverse the array from left to right.
2. For each index:
   - Check left condition.
   - Check right condition.
3. If both are true, return the index.
4. If no peak exists, return -1.

Time Complexity: O(n)
Space Complexity: O(1)
-----------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {

            bool left = (i == 0) || (nums[i] > nums[i - 1]);
            bool right = (i == n - 1) || (nums[i] > nums[i + 1]);

            if(left && right) {
                return i;
            }
        }

        return -1;
    }
};


/*
-----------------------------------------------------------
Problem: 162. Find Peak Element
Link: https://leetcode.com/problems/find-peak-element/

Approach: Binary Search

Intuition:
A peak element is greater than its adjacent elements.

Observation:
1. If nums[mid] is a peak, return mid.
2. If nums[mid] < nums[mid + 1],
   we are on an increasing slope, so a peak
   must exist on the right side.
3. Otherwise, we are on a decreasing slope,
   so a peak must exist on the left side
   (possibly at mid itself).

Using this property, we can eliminate half
of the search space in every iteration.

Algorithm:
1. Handle edge cases:
   - Single element array.
   - First element is a peak.
   - Last element is a peak.
2. Apply binary search on indices [1, n-2].
3. Check whether mid is a peak.
4. Move left or right based on the slope.
5. Return the peak index.

Time Complexity: O(log n)
Space Complexity: O(1)
-----------------------------------------------------------
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        if (n == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[n - 1] > nums[n - 2]) return n - 1;

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (nums[mid] < nums[mid + 1]) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};