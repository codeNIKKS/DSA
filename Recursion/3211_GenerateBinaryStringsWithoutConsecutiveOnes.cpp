/*
    Problem: Generate Binary Strings Without Consecutive 1s
    Approach: Recursion + Backtracking

    Intuition:
    We build the binary string one character at a time.

    At every step:
    1. We can always append '0'.
    2. We can append '1' only when the previous character is '0'.
       This prevents consecutive 1s.

    When curr reaches length n, we have formed a valid string
    and add it to the result.

    Backtracking:
    Each recursive call receives its own copy of curr because
    curr is passed by value. Therefore, when a recursive call
    returns, the previous curr automatically remains unchanged.

    Example for n = 3:

                    ""
                  /    \
                0        1
              /  \       |
            00    01     10
           / \     |    /  \
         000 001  010  100 101

    Result:
    ["000", "001", "010", "100", "101"]

    Time Complexity: O(F(n) * n)
        F(n) = number of valid binary strings
        We spend O(n) to store each completed string.

    Space Complexity: O(n)
        Recursion depth is n, excluding the output array.
*/

class Solution {
public:

    void generate(int n, string curr, vector<string>& result) {

        // Base case: valid string of length n is formed
        if (curr.length() == n) {
            result.push_back(curr);
            return;
        }

        // We can always append 0
        generate(n, curr + '0', result);

        // Append 1 only when it does not create consecutive 1s
        if (curr.empty() || curr.back() == '0') {
            generate(n, curr + '1', result);
        }
    }

    vector<string> generateBinaryStrings(int n) {

        vector<string> result;

        generate(n, "", result);

        return result;
    }
};