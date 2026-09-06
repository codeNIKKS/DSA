/*
LeetCode 17 - Letter Combinations of a Phone Number

Approach:
- Use recursion + backtracking.
- Each digit maps to a group of letters, such as 2 -> "abc".
- At every index, try each possible letter for that digit.
- Add a letter to `curr`, recursively process the next digit,
  then remove it using `pop_back()` to try another letter.
- When all digits are processed, add `curr` to `ans`.

Time Complexity: O(4^N * N)
Space Complexity: O(N), excluding the output list
*/

class Solution {
public:
    void solve(int index, string& digits,
               vector<string>& keypad,
               vector<string>& ans,
               string& curr) {

        // One letter has been chosen for every digit
        if (index == digits.size()) {
            ans.push_back(curr);
            return;
        }

        int digit = digits[index] - '0';
        string letters = keypad[digit];

        // Try every letter mapped to the current digit
        for (char ch : letters) {
            curr.push_back(ch);

            solve(index + 1, digits, keypad, ans, curr);

            curr.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }

        vector<string> keypad = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string curr;

        solve(0, digits, keypad, ans, curr);

        return ans;
    }
};