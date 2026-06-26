/*
===========================================
876. Middle of the Linked List (Brute Force)
===========================================

Approach:
1. Traverse the linked list once to count the total number of nodes.
2. Compute the middle index:
      middle = count / 2
   - For odd length, this gives the exact middle.
   - For even length, integer division automatically gives the second middle.
3. Traverse the list again and move 'middle' steps from the head.
4. Return the current node.

Example:
1 -> 2 -> 3 -> 4 -> 5
Count = 5
Middle Index = 5/2 = 2
Move 2 steps → Node 3

Time Complexity : O(N) + O(N) = O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        // Step 1: Count total nodes
        int count = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // Step 2: Find middle index
        int middle = count / 2;

        // Step 3: Traverse to middle node
        temp = head;
        while (middle--) {
            temp = temp->next;
        }

        // Step 4: Return middle node
        return temp;
    }
};

/*
===========================================
876. Middle of the Linked List (Optimal)
===========================================

Approach:
1. Use two pointers:
   - 'slow' moves one step at a time.
   - 'fast' moves two steps at a time.
2. As fast covers twice the distance of slow, when fast reaches the
   end of the linked list, slow will be at the middle.
3. If the list has an even number of nodes, slow naturally points to
   the second middle node, which is exactly what the problem asks.
4. Return the slow pointer.

Example:
1 -> 2 -> 3 -> 4 -> 5

Initially:
S
F

Iteration 1:
1 -> 2 -> 3 -> 4 -> 5
     S
          F

Iteration 2:
1 -> 2 -> 3 -> 4 -> 5
          S
               F

Fast reaches the end.
Return slow (Node 3).

Time Complexity : O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* middleNode(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};