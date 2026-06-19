/*
=========================================================
1021. Remove Outermost Parentheses
=========================================================

Problem Link:
https://leetcode.com/problems/remove-outermost-parentheses/

---------------------------------------------------------
Intuition
---------------------------------------------------------
A primitive valid parentheses string always starts with an
outer '(' and ends with its matching ')'.

If we keep track of the current nesting depth:
- The first '(' of a primitive appears when depth changes
  from 0 -> 1, so we skip it.
- The last ')' of a primitive appears when depth changes
  from 1 -> 0, so we skip it.
- All other parentheses belong to the inner part and are
  added to the answer.

---------------------------------------------------------
Approach
---------------------------------------------------------
1. Maintain a counter 'depth'.
2. For every '(':
      - If depth > 0, add it to answer.
      - Increment depth.
3. For every ')':
      - Decrement depth.
      - If depth > 0, add it to answer.
4. Return the constructed string.

---------------------------------------------------------
Time Complexity
---------------------------------------------------------
O(n)

---------------------------------------------------------
Space Complexity
---------------------------------------------------------
O(n)
(for the output string)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string ans;

        for (char ch : s) {
            if (ch == '(') {
                if (depth > 0) ans += ch;
                depth++;
            } 
            else {
                depth--;
                if (depth > 0) ans += ch;
            }
        }

        return ans;
    }
};


/*
=========================================================
1021. Remove Outermost Parentheses
=========================================================

Problem Link:
https://leetcode.com/problems/remove-outermost-parentheses/

---------------------------------------------------------
Intuition
---------------------------------------------------------
The outermost parentheses of every primitive valid
parentheses string are the first '(' and the last ')'.

Using a stack, we can track the nesting level:
- When encountering '(', if the stack is not empty,
  it is not an outermost parenthesis, so add it.
- Push '(' into the stack.
- When encountering ')', pop first.
- If the stack is still not empty after popping,
  it is not an outermost parenthesis, so add it.

---------------------------------------------------------
Approach
---------------------------------------------------------
1. Initialize an empty stack and answer string.
2. Traverse the string:
   - For '(':
       * If stack is not empty, append it.
       * Push '(' into stack.
   - For ')':
       * Pop from stack.
       * If stack is not empty, append it.
3. Return the answer string.

---------------------------------------------------------
Time Complexity
---------------------------------------------------------
O(n)

---------------------------------------------------------
Space Complexity
---------------------------------------------------------
O(n)
(stack)

=========================================================
*/

class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        string ans;

        for(char ch : s) {
            if(ch == '(') {
                if(!st.empty()) ans += ch;
                st.push(ch);
            }
            else {
                st.pop();
                if(!st.empty()) ans += ch;
            }
        }

        return ans;
    }
};