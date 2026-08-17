/*
    LeetCode 22 - Generate Parentheses

    Problem:
    Given n pairs of parentheses, generate all combinations
    of well-formed parentheses.

    Approach:
    - Use backtracking to build the string character by character.
    - `s` represents the current balance:
          s = number of '(' - number of ')'
    - We can add '(' only when we still have enough positions
      left to eventually close all opened parentheses.
    - We can add ')' only when s > 0, meaning there is an
      unmatched '(' available to close.
    - When the string length becomes 2*n and s == 0,
      we have found a valid combination.

    Opening '(' condition:
        s < (2*n - curr.length())

    Derivation:
        Let O = number of '('
        Let C = number of ')'

        curr.length() = O + C
        s = O - C

        Therefore:
        O = (curr.length() + s) / 2

        We need O < n:
        (curr.length() + s) / 2 < n

        => curr.length() + s < 2*n
        => s < 2*n - curr.length()

    Closing ')' condition:
        s > 0

    Time Complexity:
        O(Cn * n), where Cn is the nth Catalan number,
        because there are Cn valid combinations and each
        string has length 2*n.

    Space Complexity:
        O(n) auxiliary recursion stack
        (excluding the output array).
*/

class Solution {
public:
    void generate(int n, string curr, int s,
                  vector<string>& result) {

        // Valid complete combination
        if (curr.length() == 2 * n && s == 0) {
            result.push_back(curr);
            return;
        }

        // Add '(' only if we have not used all n opening brackets
        if (s < (2 * n - curr.length())) {
            generate(n, curr + '(', s + 1, result);
        }

        // Add ')' only if there is an unmatched '('
        if (s > 0) {
            generate(n, curr + ')', s - 1, result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n, "", 0, result);
        return result;
    }
};