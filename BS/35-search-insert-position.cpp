/*
=========================================================
LeetCode 35. Search Insert Position
=========================================================

Problem:
Given a sorted array of distinct integers and a target value,
return the index if the target is found. If not, return the
index where it would be inserted in order.

Example:
Input: nums = [1,3,5,6], target = 5
Output: 2

Input: nums = [1,3,5,6], target = 2
Output: 1

---------------------------------------------------------
Intuition:
---------------------------------------------------------
The required position is the first index where the element
is greater than or equal to the target.

This is exactly the definition of Lower Bound.

After a lower bound binary search:
    high -> last element < target
    low  -> first element >= target

Therefore, 'low' directly represents the answer.

---------------------------------------------------------
Approach:
---------------------------------------------------------
1. Apply Binary Search.
2. If nums[mid] >= target:
      Search on the left half.
3. Otherwise:
      Search on the right half.
4. When the loop ends, low points to the insertion position.
5. Return low.

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------
O(log n)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------
O(1)

=========================================================
*/
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] >= target) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};