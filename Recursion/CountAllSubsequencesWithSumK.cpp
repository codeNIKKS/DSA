/*
    Problem: Count all Subsequences with Sum K

    Approach:
    Use recursion/backtracking. For every element, we have two choices:
    1. Include the current element in the subsequence.
    2. Exclude the current element.

    When we reach the end of the array:
    - If the current sum is equal to k, we found one valid subsequence.
    - Otherwise, it is not a valid subsequence.

    Since all elements are positive, if sum becomes greater than k,
    we can immediately stop that recursive branch.

    Time Complexity:
    O(2^N)

    Space Complexity:
    O(N)  // Recursion stack
*/

class Solution {
public:
    int count(int index, int sum, vector<int>& nums, int k) {
        // Since all elements are positive, no future addition
        // can bring the sum back down to k.
        if (sum > k)
            return 0;

        // Base case: all elements have been processed.
        if (index == nums.size()) {
            return (sum == k) ? 1 : 0;
        }

        // Choice 1: Include nums[index]
        sum += nums[index];
        int left = count(index + 1, sum, nums, k);

        // Backtrack
        sum -= nums[index];

        // Choice 2: Exclude nums[index]
        int right = count(index + 1, sum, nums, k);

        return left + right;
    }

    int countSubsequenceWithTargetSum(vector<int>& nums, int k) {
        return count(0, 0, nums, k);
    }
};