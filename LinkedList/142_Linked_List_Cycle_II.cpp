/*
=========================================================
LeetCode 142. Linked List Cycle II
Brute Force Approach (Using Hash Map)

Approach:
1. Traverse the linked list from the head.
2. Store every visited node's address in an unordered_map.
3. Before visiting a node, check if it already exists in the map.
4. If it does, that node is the starting point of the cycle.
5. If traversal reaches NULL, no cycle exists.

Time Complexity: O(N)
Space Complexity: O(N)

---------------------------------------------------------
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> visited;

        ListNode* temp = head;

        while (temp != NULL) {
            if (visited[temp]) {
                return temp;
            }

            visited[temp] = true;
            temp = temp->next;
        }

        return NULL;
    }
};


/*
=========================================================
LeetCode 142. Linked List Cycle II
Optimal Approach (Floyd's Cycle Detection Algorithm)

Intuition:
- Use two pointers:
  • Slow moves one step at a time.
  • Fast moves two steps at a time.
- If a cycle exists, both pointers will eventually meet.
- Once they meet, move the slow pointer back to the head.
- Now move both pointers one step at a time.
- The node where they meet again is the starting point of the cycle.

Approach:
1. Initialize slow and fast pointers at the head.
2. Move slow by one step and fast by two steps.
3. If they never meet, return NULL (no cycle).
4. If they meet:
   - Reset slow to head.
   - Move both pointers one step at a time.
   - Return the node where they meet.

Time Complexity: O(N)
Space Complexity: O(1)

---------------------------------------------------------
*/

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                slow = head;

                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }

                return slow;
            }
        }

        return NULL;
    }
};