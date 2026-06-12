/*
    LeetCode 410. Split Array Largest Sum

    Approach:
    - The answer lies between:
        low  = maximum element in nums
        high = sum of all elements
    - Binary search on this range.
    - For a candidate maximum sum (mid),
      greedily form subarrays such that each
      subarray sum does not exceed mid.
    - Count how many subarrays are required.
    - If required subarrays <= k:
          mid is a valid answer,
          try finding a smaller one.
      Else:
          increase the allowed maximum sum.

    Time Complexity: O(n * log(sum(nums) - max(nums)))
    Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int subarrays = 1;
            long long currSum = 0;

            for (int i = 0; i < nums.size(); i++) {

                if (currSum + nums[i] <= mid) {
                    currSum += nums[i];
                }
                else {
                    subarrays++;
                    currSum = nums[i];
                }
            }

            if (subarrays <= k) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};