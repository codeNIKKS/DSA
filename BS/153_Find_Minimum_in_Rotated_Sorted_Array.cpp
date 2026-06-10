/*
    Problem: Find Minimum in Rotated Sorted Array
    Approach: Binary Search on Rotated Sorted Array

    Intuition:
    In a rotated sorted array, at least one half is always sorted.
    The minimum element can either be the first element of the sorted
    half or lie inside the unsorted half.

    Time Complexity: O(log n)
    Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {

            // Entire search space is sorted
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half is sorted
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};