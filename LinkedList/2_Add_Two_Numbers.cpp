/*
=========================================================
LeetCode 2. Add Two Numbers
=========================================================

Problem:
Given two non-empty linked lists representing two non-negative integers,
where the digits are stored in reverse order, return the sum as a linked list.

---------------------------------------------------------
Intuition:
---------------------------------------------------------
- Traverse both linked lists simultaneously.
- At each step, add:
    1. Current node of first list (if present)
    2. Current node of second list (if present)
    3. Carry from the previous addition
- Store the last digit (sum % 10) in a new node.
- Carry forward the remaining digit (sum / 10).
- Continue until both lists are exhausted.
- If a carry remains at the end, create one final node.

A dummy node is used to simplify insertion into the answer list.

---------------------------------------------------------
Approach:
---------------------------------------------------------
1. Create a dummy node and a pointer `curr`.
2. Initialize carry = 0.
3. While either list has nodes:
      - sum = carry
      - Add values from available nodes.
      - Create a new node with (sum % 10).
      - Update carry = sum / 10.
      - Move all pointers forward.
4. If carry still exists, append one last node.
5. Store dummy->next in a separate pointer.
6. Delete the dummy node to avoid memory leak.
7. Return the head of the answer list.

---------------------------------------------------------
Time Complexity: O(max(N, M))
Space Complexity: O(max(N, M))
(Excluding the output list: O(1) auxiliary space)

=========================================================
*/

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {

            int sum = carry;

            if (l1) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        if (carry) {
            curr->next = new ListNode(carry);
        }

        ListNode* ans = dummy->next;
        delete dummy;

        return ans;
    }
};