/*
=========================================================
2095. Delete the Middle Node of a Linked List
=========================================================

Problem:
Given the head of a singly linked list, delete the middle node
of the linked list and return the head of the modified list.

---------------------------------------------------------
Brute Force Approach (Count Length)
---------------------------------------------------------

Intuition:
- First, count the total number of nodes in the linked list.
- The middle node is at index (n / 2) using 0-based indexing.
- Traverse the list again until reaching the node just before
  the middle node.
- Adjust its next pointer to skip the middle node.
- Delete the removed node.

---------------------------------------------------------
Algorithm:
1. If the list has only one node, delete it and return NULL.
2. Traverse once to calculate the length 'n'.
3. Compute middle = n / 2.
4. Traverse again until reaching the (middle-1)th node.
5. Delete the middle node by changing pointers.
6. Return the head.

---------------------------------------------------------
Time Complexity: O(N) | Space Complexity: O(1)
---------------------------------------------------------
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL)
            return NULL;

        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        int n = 0;
        ListNode* temp = head;

        while (temp != NULL) {
            n++;
            temp = temp->next;
        }

        int middle = n / 2;
        temp = head;

        while (middle > 1) {
            temp = temp->next;
            middle--;
        }

        ListNode* midNode = temp->next;
        temp->next = temp->next->next;
        delete midNode;

        return head;
    }
};


/*
=========================================================
2095. Delete the Middle Node of a Linked List
=========================================================

Problem:
Given the head of a singly linked list, delete the middle node
of the linked list and return the head of the modified list.

---------------------------------------------------------
Optimal Approach (Slow & Fast Pointers)
---------------------------------------------------------

Intuition:
- Use two pointers:
    • slow moves one step at a time.
    • fast moves two steps at a time.
- Initialize fast two nodes ahead of slow.
- This ensures that when fast reaches the end of the list,
  slow is positioned just before the middle node.
- Delete slow->next by updating pointers.

---------------------------------------------------------
Algorithm:
1. If the list is empty, return NULL.
2. If the list has only one node, delete it and return NULL.
3. Initialize:
       slow = head
       fast = head->next->next
4. Move:
       slow = slow->next
       fast = fast->next->next
   while fast and fast->next exist.
5. Delete slow->next.
6. Return the head.

---------------------------------------------------------
Time Complexity: O(N) | Space Complexity: O(1)
---------------------------------------------------------
*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        if (head == NULL)
            return NULL;

        if (head->next == NULL) {
            delete head;
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head->next->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* midNode = slow->next;
        slow->next = slow->next->next;
        delete midNode;

        return head;
    }
};