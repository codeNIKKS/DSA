/*
    Problem: Check if there exists a Subsequence with Sum K

    Approach:
    Use recursion/backtracking. At every index, we have two choices:
    1. Include the current element.
    2. Exclude the current element.

    If we reach the end of the array:
    - If sum == k, a valid subsequence exists → return true.
    - Otherwise, return false.

    We immediately stop a branch if sum > k because all elements
    in the array are positive.

    The `true` result is propagated back immediately using short-circuiting.

    Time Complexity: O(2^N)
    Space Complexity: O(N) - recursion stack
*/

class Solution {
public:
    bool check(int i, int sum, vector<int>& nums, int k) {

        // Pruning
        if (sum > k)
            return false;

        // Base case
        if (i == nums.size()) {
            return sum == k;
        }

        // Include current element
        sum += nums[i];

        if (check(i + 1, sum, nums, k))
            return true;

        // Backtrack
        sum -= nums[i];

        // Exclude current element
        if (check(i + 1, sum, nums, k))
            return true;

        return false;
    }

    bool checkSubsequenceSum(vector<int>& nums, int k) {
        return check(0, 0, nums, k);
    }
};