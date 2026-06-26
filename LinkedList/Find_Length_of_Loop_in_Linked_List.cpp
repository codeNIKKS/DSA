/*
=========================================================
| Length of Loop in Linked List (Brute Force - Hash Map) |
=========================================================

Problem:
Given the head of a singly linked list, return the length of the loop
if a cycle exists; otherwise, return 0.

---------------------------------------------------------
Intuition:
---------------------------------------------------------
- Traverse the linked list while storing every visited node
  along with the step number at which it was first visited.
- If a node is encountered again, a cycle exists.
- The difference between the current step and the first
  occurrence of that node gives the length of the loop.

---------------------------------------------------------
Approach:
---------------------------------------------------------
1. Create an unordered_map<Node*, int>.
2. Store each visited node with its traversal index.
3. Traverse the linked list:
   - If the node is not present in the map:
       -> Store {node, currentStep}.
   - Else:
       -> Loop detected.
       -> Return currentStep - firstVisitedStep.
4. If traversal reaches NULL, return 0.

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------
O(N)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------
O(N)

---------------------------------------------------------
GitHub:
---------------------------------------------------------
Uses hashing to remember the first occurrence of every node.
When a node is revisited, the difference in traversal steps
gives the exact length of the cycle.
*/

class Solution {
public:
    int findLengthOfLoop(ListNode *head) {
        unordered_map<ListNode*, int> visited;

        ListNode* temp = head;
        int step = 0;

        while (temp != NULL) {
            if (visited.find(temp) != visited.end()) {
                return step - visited[temp];
            }

            visited[temp] = step;
            step++;
            temp = temp->next;
        }

        return 0;
    }
};


/*
=========================================================
| Length of Loop in Linked List (Optimal - Floyd's Cycle Detection) |
=========================================================

Problem:
Given the head of a singly linked list, return the length of the loop
if a cycle exists; otherwise, return 0.

---------------------------------------------------------
Intuition:
---------------------------------------------------------
- Use Floyd's Cycle Detection Algorithm (Tortoise and Hare)
  to determine whether a cycle exists.
- If the slow and fast pointers meet, a cycle is present.
- Starting from the meeting point, traverse the cycle once
  until reaching the same node again while counting the
  number of nodes visited.
- The count obtained is the length of the loop.

---------------------------------------------------------
Approach:
---------------------------------------------------------
1. Initialize two pointers:
      - slow moves one step at a time.
      - fast moves two steps at a time.
2. Traverse the linked list:
      - If fast reaches NULL, no cycle exists.
      - If slow == fast, a cycle is detected.
3. From the meeting node:
      - Move one pointer around the cycle.
      - Count the number of nodes until it returns to the
        meeting node.
4. Return the count.
5. If no cycle is found, return 0.

---------------------------------------------------------
Time Complexity:
---------------------------------------------------------
O(N)

---------------------------------------------------------
Space Complexity:
---------------------------------------------------------
O(1)

---------------------------------------------------------
GitHub:
---------------------------------------------------------
Uses Floyd's Cycle Detection Algorithm to detect a loop
without extra space. Once a meeting point is found, one
complete traversal of the cycle gives its length.
*/

class Solution {
public:
    int findCycleLength(ListNode* meetingNode) {
        int cnt = 1;
        ListNode* temp = meetingNode->next;

        while (temp != meetingNode) {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    int findLengthOfLoop(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return findCycleLength(slow);
        }

        return 0;
    }
};