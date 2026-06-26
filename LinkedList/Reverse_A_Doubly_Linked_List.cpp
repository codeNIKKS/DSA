/*
===============================================================================
Problem    : Reverse a Doubly Linked List (Brute Force)
Platform   : GeeksforGeeks
Approach   : Stack
Time       : O(N)
Space      : O(N)
===============================================================================

Intuition:
- A stack follows the Last In First Out (LIFO) principle.
- If we push all node values into a stack, popping them will give the values
  in reverse order.
- Traverse the doubly linked list twice:
    1. Store every node's value in the stack.
    2. Replace each node's value with the top element of the stack.
- The node connections remain unchanged; only the values are reversed.

Algorithm:
1. If the list is empty or has one node, return head.
2. Traverse the DLL and push every node's data into a stack.
3. Traverse the DLL again from the head.
4. Replace each node's data with stack.top() and pop it.
5. Return the original head.

Complexity:
- Time : O(N)
- Space: O(N)

Note:
- This is a brute-force solution because it uses extra space.
- It reverses only the node values, not the actual links.
- The optimal approach reverses the prev and next pointers in O(1) extra space.
===============================================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        stack<int> st;
        ListNode* temp = head;

        // Store all node values
        while (temp != nullptr) {
            st.push(temp->data);
            temp = temp->next;
        }

        temp = head;

        // Replace values in reverse order
        while (temp != nullptr) {
            temp->data = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};


/*
===============================================================================
Problem    : Reverse a Doubly Linked List (Optimal)
Platform   : GeeksforGeeks
Approach   : In-Place Pointer Reversal
Time       : O(N)
Space      : O(1)
===============================================================================

Intuition:
- In a doubly linked list, every node has both prev and next pointers.
- To reverse the list, simply swap these two pointers for every node.
- After swapping, move to the original next node (which is now stored in prev).
- Once all nodes are processed, the last processed node becomes the new head.

Algorithm:
1. If the list is empty or has only one node, return head.
2. Traverse the DLL node by node.
3. For every node:
   - Swap its prev and next pointers.
   - Move to the next node using curr = curr->prev.
4. After the traversal, return the new head
   (last processed node's previous pointer).

Complexity:
- Time : O(N)
- Space: O(1)

Why this is Optimal:
- Every node is visited exactly once.
- No extra data structure is used.
- The actual links of the doubly linked list are reversed in-place.
===============================================================================
*/

class Solution {
public:
    ListNode* reverseDLL(ListNode* head) {

        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* curr = head;
        ListNode* last = nullptr;

        while (curr != nullptr) {

            // Swap prev and next pointers
            last = curr->prev;
            curr->prev = curr->next;
            curr->next = last;

            // Move to the original next node
            curr = curr->prev;
        }

        // Return the new head
        return last->prev;
    }
};