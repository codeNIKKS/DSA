/*
=========================================
LeetCode 206. Reverse Linked List
Approach: Brute Force (Using Stack)
=========================================

Intuition:
-----------
Instead of reversing the links between the nodes, store all node values
in a stack. Since a stack follows LIFO (Last In, First Out), popping the
elements gives the values in reverse order. Traverse the linked list again
and overwrite each node's value with the popped value.

Approach:
----------
1. Traverse the linked list and push every node's value into a stack.
2. Reset the traversal pointer to the head.
3. Traverse the list again:
   - Assign the top value of the stack to the current node.
   - Pop the value from the stack.
4. Return the original head.

Time Complexity: O(N)
Space Complexity: O(N)

Note:
-----
This approach reverses only the node values, NOT the actual links.
The expected interview solution is the in-place pointer reversal
with O(1) extra space.
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        stack<int> st;
        ListNode* temp = head;

        // Store all node values
        while(temp != NULL) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Replace values in reverse order
        temp = head;
        while(temp != NULL) {
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }
};


/*
=========================================
LeetCode 206. Reverse Linked List
Approach: Optimal (Iterative - Three Pointers)
=========================================

Intuition:
-----------
To reverse a linked list in-place, we need to reverse the direction of
every 'next' pointer. While doing so, we must not lose access to the
remaining part of the list, so we first store the next node before
changing the current node's link.

Approach:
----------
1. Initialize three pointers:
   - prev = NULL
   - curr = head
   - front = NULL
2. Traverse the linked list until curr becomes NULL:
   - Store the next node in front.
   - Reverse the current node's link (curr->next = prev).
   - Move prev one step ahead.
   - Move curr one step ahead using front.
3. When the traversal ends, prev points to the new head.
4. Return prev.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front = NULL;

        while(curr != NULL) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }
};