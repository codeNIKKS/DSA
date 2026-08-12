// File: Sort_a_Stack.cpp
// Problem: Sort a Stack
// Approach: Recursion + Recursive Sorted Insertion
//
// Intuition:
// 1. Pop the top element.
// 2. Recursively sort the remaining stack.
// 3. Insert the popped element into its correct position.
// 4. No extra data structure is used.
//
// Time Complexity: O(N^2)
// Space Complexity: O(N) - recursion stack

class Solution {
public:

    void insert(stack<int>& st, int temp) {
        // Correct position found
        if (st.empty() || st.top() <= temp) {
            st.push(temp);
            return;
        }

        // Remove larger element temporarily
        int val = st.top();
        st.pop();

        // Insert temp into the remaining stack
        insert(st, temp);

        // Put the removed element back
        st.push(val);
    }

    void sortStack(stack<int>& st) {
        // Base case
        if (st.empty()) {
            return;
        }

        // Remove top element
        int temp = st.top();
        st.pop();

        // Sort remaining stack
        sortStack(st);

        // Insert removed element at correct position
        insert(st, temp);
    }
};