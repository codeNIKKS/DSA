/*
    LeetCode 540. Single Element in a Sorted Array

    Intuition:
    In a sorted array where every element appears exactly twice except one,
    all pairs appear consecutively.

    Before the single element:
    - First occurrence is at an even index.
    - Second occurrence is at an odd index.

    After the single element:
    - The pairing pattern breaks.
    - First occurrence shifts to an odd index.
    - Second occurrence shifts to an even index.

    We use Binary Search to locate the point where this pattern breaks.

    Approach:
    1. Handle edge cases:
       - Array size = 1
       - Single element at first index
       - Single element at last index

    2. Binary Search in range [1, n-2].

    3. If nums[mid] is different from both neighbours,
       it is the answer.

    4. Determine which side is sorted correctly:
       - Even index should match next element.
       - Odd index should match previous element.

       If pattern is correct:
           Search right half.
       Else:
           Search left half.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        // Edge Cases
        if (n == 1) return nums[0];

        if (nums[0] != nums[1]) return nums[0];

        if (nums[n - 1] != nums[n - 2]) return nums[n - 1];

        int low = 1;
        int high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Single element found
            if (nums[mid] != nums[mid - 1] &&
                nums[mid] != nums[mid + 1]) {
                return nums[mid];
            }

            // Pairing pattern is correct
            if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) ||
                (mid % 2 == 0 && nums[mid] == nums[mid + 1])) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};