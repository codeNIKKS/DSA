/*
-------------------------------------------------------
Problem No. : 237
Problem Name: Delete Node in a Linked List
Link        : https://leetcode.com/problems/delete-node-in-a-linked-list/

Intuition:
We are not given the head of the linked list, only the
node that needs to be deleted.

Since we cannot access the previous node, we cannot
remove the current node in the usual way.

The key observation is that the given node is guaranteed
to not be the last node. Therefore, we can copy the value
of the next node into the current node and then delete
the next node instead.

Approach:
1. Copy the value of the next node into the current node.
2. Store the next node in a temporary pointer.
3. Update the current node's next pointer to skip the
   next node.
4. Delete the stored node.

Time Complexity : O(1)
Space Complexity: O(1)
-------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;

        ListNode* temp = node->next;
        node->next = node->next->next;

        delete temp;
    }
};