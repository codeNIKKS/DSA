/*
===========================================
LeetCode 19. Remove Nth Node From End of List
Brute Force Approach (Length Calculation)
===========================================

Intuition:
- First, calculate the total number of nodes in the linked list.
- The node to be deleted is the (Length - n + 1)th node from the beginning.
- Traverse again to reach the node just before the target node.
- Update the links to remove the target node.

Approach:
1. Traverse the linked list once to calculate its length.
2. If n equals the length, remove the head node.
3. Otherwise, move to the (Length - n)th node.
4. Change its next pointer to skip the target node.
5. Delete the removed node and return the head.

Time Complexity: O(2N) ≈ O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int length = 0;
        ListNode* temp = head;

        // Calculate length of linked list
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // If head needs to be deleted
        if (length == n) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        int steps = length - n;
        temp = head;

        // Reach node just before the one to delete
        while (steps > 1) {
            temp = temp->next;
            steps--;
        }

        ListNode* delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;

        return head;
    }
};


/*
=======================================================
LeetCode 19. Remove Nth Node From End of List
Optimal Approach (Two Pointers / Fast & Slow)
=======================================================

Intuition:
- Instead of traversing the list twice, use two pointers.
- Move the fast pointer n steps ahead.
- If the fast pointer becomes NULL after moving n steps, the head is the node to remove.
- Otherwise, move both fast and slow pointers together until fast reaches the last node.
- At this point, slow will be just before the node to be deleted.

Approach:
1. Move the fast pointer n nodes ahead.
2. If fast becomes NULL, delete the head node.
3. Move both fast and slow pointers one step at a time.
4. Stop when fast reaches the last node.
5. Delete slow->next by updating the links.
6. Return the head.

Time Complexity: O(N)
Space Complexity: O(1)
*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* fast = head;
        ListNode* slow = head;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // If head needs to be removed
        if (fast == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }

        // Move both pointers together
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Remove the target node
        ListNode* delNode = slow->next;
        slow->next = delNode->next;
        delete delNode;

        return head;
    }
};