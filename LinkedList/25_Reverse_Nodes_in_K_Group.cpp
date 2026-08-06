/*
=========================================================
LeetCode 25. Reverse Nodes in k-Group
=========================================================

Problem:
Reverse the nodes of a linked list k at a time. If the
remaining nodes are fewer than k, leave them unchanged.

Approach:
1. Find the kth node from the current node.
2. If fewer than k nodes remain, connect the previous
   group's tail to the current node and stop.
3. Store the next group's starting node.
4. Detach the current group.
5. Reverse the current group.
6. Connect the previous group with the reversed group.
7. Move to the next group and repeat.

Time Complexity: O(N)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* temp = head;
        ListNode* prev = NULL;

        while (temp != NULL) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }

        return prev;
    }

    ListNode* findKthNode(ListNode* temp, int k) {
        k--;

        while (temp != NULL && k > 0) {
            temp = temp->next;
            k--;
        }

        return temp;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while (temp != NULL) {
            ListNode* kthNode = findKthNode(temp, k);

            if (kthNode == NULL) {
                if (prevNode)
                    prevNode->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;

            reverseLL(temp);

            if (temp == head)
                head = kthNode;
            else
                prevNode->next = kthNode;

            prevNode = temp;
            temp = nextNode;
        }

        return head;
    }
};