/*
LeetCode 216 - Combination Sum III

Approach:
- Use recursion + backtracking.
- Try every possible next number from `start` through 9.
- After choosing number `i`, start the next loop from `i + 1`.
  This ensures every number is used only once and avoids duplicates.
- `curr` stores the current combination.
- When `curr` has exactly `k` numbers, add it to `result`
  only if their sum equals `n`.
- `pop_back()` removes the last chosen number so the loop can
  try the next possible number.

Time Complexity: O(2^9 * k)
Space Complexity: O(k), excluding the output list
*/

class Solution {
public:
    void combination(int k, int n, int start,
                     vector<vector<int>>& result,
                     vector<int>& curr) {
        
        // Chose k numbers
        if (curr.size() == k) {
            if (n == 0) {
                result.push_back(curr);
            }
            return;
        }

        // Try the next number from start to 9
        for (int i = start; i <= 9; i++) {
            // i is already larger than the remaining required sum
            if (i > n) {
                break;
            }

            // Choose i
            curr.push_back(i);

            // Next number must be greater than i
            combination(k, n - i, i + 1, result, curr);

            // Remove i before trying the next loop value
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;

        combination(k, n, 1, result, curr);

        return result;
    }
};