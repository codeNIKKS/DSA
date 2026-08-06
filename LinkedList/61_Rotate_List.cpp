/*
================================================================================
Problem: 61. Rotate List
Link: https://leetcode.com/problems/rotate-list/

Approach: Optimal (Circular Linked List)

Intuition:
- First, calculate the length of the linked list while finding the last node.
- If k is a multiple of the length, no rotation is needed.
- Otherwise, connect the last node to the head, making the list circular.
- Find the new tail at (length - k)th node.
- The node after the new tail becomes the new head.
- Break the circular link and return the new head.

Time Complexity: O(N)
Space Complexity: O(1)
================================================================================
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* findNthNode(ListNode* temp, int n) {
        n--;
        while (temp != NULL && n > 0) {
            temp = temp->next;
            n--;
        }
        return temp;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        // Edge Cases
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and tail
        int len = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            len++;
            tail = tail->next;
        }

        k %= len;
        if (k == 0)
            return head;

        // Make circular linked list
        tail->next = head;

        // Find new tail
        ListNode* newTail = findNthNode(head, len - k);

        // New head
        ListNode* newHead = newTail->next;

        // Break the circle
        newTail->next = NULL;

        return newHead;
    }
};