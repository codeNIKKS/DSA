/*
=========================================================
📌 Problem: 141. Linked List Cycle
🔗 Link: https://leetcode.com/problems/linked-list-cycle/

🧠 Intuition:
If a linked list contains a cycle, we will eventually visit the
same node more than once while traversing the list.

We can store every visited node in a hash map.
- If the current node is already present in the map, a cycle exists.
- Otherwise, mark it as visited and continue traversing.

---------------------------------------------------------
🚀 Approach:
1. Create an unordered_map to store visited node addresses.
2. Traverse the linked list from the head.
3. For each node:
   - If it is already present in the map, return true.
   - Otherwise, mark it as visited.
4. If traversal reaches NULL, no cycle exists.

---------------------------------------------------------
⏱️ Time Complexity: O(N)
- Each node is visited at most once.

📦 Space Complexity: O(N)
- Hash map stores all visited nodes.
=========================================================
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        unordered_map<ListNode*, bool> visited;

        ListNode* temp = head;

        while (temp != NULL) {

            if (visited[temp])
                return true;

            visited[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};


/*
=========================================================
📌 Problem: 141. Linked List Cycle
🔗 Link: https://leetcode.com/problems/linked-list-cycle/

🧠 Intuition:
If a cycle exists in the linked list, two pointers moving at
different speeds will eventually meet inside the cycle.

Use Floyd's Cycle Detection Algorithm (Tortoise and Hare):
- Slow pointer moves one step at a time.
- Fast pointer moves two steps at a time.
- If they ever meet, a cycle exists.
- If the fast pointer reaches NULL, no cycle exists.

---------------------------------------------------------
🚀 Approach:
1. Initialize two pointers, slow and fast, at the head.
2. Traverse the list while fast and fast->next are not NULL.
3. Move:
   - slow by one node.
   - fast by two nodes.
4. If slow == fast at any point, return true.
5. If traversal ends, return false.

---------------------------------------------------------
⏱️ Time Complexity: O(N)
- Each pointer traverses the list at most once.

📦 Space Complexity: O(1)
- No extra space is used.
=========================================================
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {

            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};