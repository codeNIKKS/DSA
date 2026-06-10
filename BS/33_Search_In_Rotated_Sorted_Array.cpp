/*
-------------------------------------------------------
Problem: Search in Rotated Sorted Array (LeetCode 33)
Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

Intuition:
- A rotated sorted array always has at least one half
  (left or right) that remains sorted.
- Use Binary Search to identify the sorted half.
- Check whether the target lies inside that sorted half.
- If yes, search there; otherwise search in the other half.

Approach:
1. Find mid.
2. If nums[mid] == target, return mid.
3. Check which half is sorted:
   - Left Half Sorted:
       nums[low] <= nums[mid]
   - Right Half Sorted:
       otherwise
4. Determine if target lies in the sorted half.
5. Eliminate the other half.
6. Continue until found or search space becomes empty.

Time Complexity: O(log N)
Space Complexity: O(1)
-------------------------------------------------------
*/
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[low] <= nums[mid]) {

                if (nums[low] <= target && target < nums[mid])
                    high = mid - 1;
                else
                    low = mid + 1;
            }

            // Right half is sorted
            else {

                if (nums[mid] < target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }

        return -1;
    }
};