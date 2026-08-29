# Combination Sum II

## Intuition

Each candidate can be used at most once, so after selecting an element at index `i`, all future choices must begin from `i + 1`.

The input can contain duplicate values. For example, choosing the first `1` or the second `1` as the first number would lead to the same combinations. To prevent duplicate answers:

1. Sort the array.
2. At each recursion level, skip a value if it is the same as the previous value at that level.

However, duplicate values can still both be selected when they exist at different indices. For `[1, 1, 2, 2]` and `target = 4`, selecting the first `1` moves the next starting position to index `1`, allowing the second `1` to be chosen. This produces `[1, 1, 2]`.

## Approach

- Sort `candidates`.
- Use backtracking to build a current combination.
- `start` marks the first index allowed for the current recursive call.
- If `candidates[i] > target`, stop because every later value is also too large.
- Skip duplicates at the same recursive depth:

```cpp
if (i > start && candidates[i] == candidates[i - 1]) continue;
```

- After choosing `candidates[i]`, recurse from `i + 1` so that the same array position cannot be reused.

## Complexity

Let `n` be the number of candidates.

- Time complexity: `O(2^n)` in the worst case, excluding the cost of copying results.
- Space complexity: `O(n)` for the recursion stack and current combination, excluding the output.

## C++ Solution

```cpp
class Solution {
public:
    vector<vector<int>> answer;
    vector<int> current;

    void backtrack(vector<int>& candidates, int start, int remaining) {
        if (remaining == 0) {
            answer.push_back(current);
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            // Skip equal values only at the same recursion level.
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            // Array is sorted, so no later value can fit either.
            if (candidates[i] > remaining) {
                break;
            }

            current.push_back(candidates[i]);

            // i + 1 ensures each candidate index is used only once.
            backtrack(candidates, i + 1, remaining - candidates[i]);

            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, 0, target);
        return answer;
    }
};
```