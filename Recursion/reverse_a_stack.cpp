/*
    Problem: Reverse a Stack Using Recursion

    Approach:
    1. Remove the top element recursively until the stack becomes empty.
    2. While returning from recursion, insert each removed element
       at the bottom of the stack.
    3. This reverses the stack.

    Helper Function:
    insertAtBottom() removes all elements above the bottom,
    inserts the given value, and then restores the removed elements.

    Time Complexity: O(N^2)
    Space Complexity: O(N) - recursion stack
*/

class Solution {
public:

    void insertAtBottom(stack<int>& st, int val) {
        if (st.empty()) {
            st.push(val);
            return;
        }

        int temp = st.top();
        st.pop();

        insertAtBottom(st, val);

        st.push(temp);
    }

    void reverseStack(stack<int>& st) {
        if (st.empty())
            return;

        int topVal = st.top();
        st.pop();

        reverseStack(st);

        insertAtBottom(st, topVal);
    }
};