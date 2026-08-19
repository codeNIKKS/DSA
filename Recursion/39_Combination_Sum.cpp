/*
    LeetCode 39 - Combination Sum

    Approach:
    - Use recursion + backtracking.
    - At every index, we have two choices:
        1. Take candidates[i]
        2. Don't take candidates[i]
    - If we take an element, we stay at the same index because
      the same candidate can be used unlimited times.
    - If we don't take it, we move to i + 1.
    - curr stores the current combination.
    - result stores all valid combinations.

    Time Complexity: O(2^N) approximately
    Space Complexity: O(Target) for recursion/current combination
*/

class Solution {
public:

    void combination(int i, int sum, vector<int>& curr,
                     vector<vector<int>>& result,
                     vector<int>& candidates, int target) {

        // Sum exceeded target
        if (sum > target)
            return;

        // All candidates processed
        if (i == candidates.size()) {
            if (sum == target)
                result.push_back(curr);

            return;
        }

        // TAKE current candidate
        curr.push_back(candidates[i]);

        combination(i, sum + candidates[i],
                    curr, result, candidates, target);

        // Backtrack
        curr.pop_back();

        // DON'T TAKE current candidate
        combination(i + 1, sum,
                    curr, result, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int> curr;
        vector<vector<int>> result;

        combination(0, 0, curr, result, candidates, target);

        return result;
    }
};