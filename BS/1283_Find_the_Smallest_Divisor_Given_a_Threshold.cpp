/*
=========================================================
LeetCode 1283. Find the Smallest Divisor Given a Threshold
=========================================================

Problem:
Given an integer array nums and an integer threshold,
find the smallest positive divisor such that the sum of
ceil(nums[i] / divisor) for all elements is less than or
equal to threshold.

---------------------------------------------------------
Intuition:
- As the divisor increases, the resulting sum decreases.
- We need the minimum divisor that satisfies the condition.
- This forms a monotonic search space:
    Small divisor -> Large sum
    Large divisor -> Small sum
- Hence, Binary Search on Answer can be applied.

---------------------------------------------------------
Approach:
1. Search divisor in range [1, max(nums)].
2. For each mid:
      sum += ceil(nums[i] / mid)
   Compute using integer math:
      (nums[i] + mid - 1) / mid
3. If sum <= threshold:
      mid is a valid divisor.
      Try finding a smaller valid divisor.
4. Else:
      divisor is too small.
      Move right.
5. Return low.

---------------------------------------------------------
Time Complexity:
O(n * log(max(nums)))

Space Complexity:
O(1)

---------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findSum(vector<int>& nums, int divisor) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += (nums[i] + divisor - 1) / divisor;
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int sum = findSum(nums, mid);

            if (sum <= threshold) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};