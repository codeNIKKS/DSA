/*
================================================================================
                            160. Intersection of Two Linked Lists
================================================================================

Problem Link:
https://leetcode.com/problems/intersection-of-two-linked-lists/

Approach: Brute Force (Using Hash Map)

Intuition:
- Traverse the first linked list and store the address of every node in a hash map.
- Traverse the second linked list.
- The first node whose address is already present in the hash map is the
  intersection node.
- If no such node exists, return NULL.

Algorithm:
1. Create an unordered_map<ListNode*, int>.
2. Traverse List A and store every node pointer in the map.
3. Traverse List B.
4. If the current node exists in the map, return it.
5. If traversal finishes without finding any common node, return NULL.

Time Complexity: O(N + M)
Space Complexity: O(N)

Where:
- N = Number of nodes in List A
- M = Number of nodes in List B

================================================================================
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_map<ListNode*, int> visited;

        ListNode* temp = headA;

        while(temp != NULL) {
            visited[temp] = 1;
            temp = temp->next;
        }

        temp = headB;

        while(temp != NULL) {
            if(visited.find(temp) != visited.end())
                return temp;

            temp = temp->next;
        }

        return NULL;
    }
};


/*
================================================================================
                    160. Intersection of Two Linked Lists
================================================================================

Problem Link:
https://leetcode.com/problems/intersection-of-two-linked-lists/

Approach: Better (Length Difference)

Intuition:
- Find the lengths of both linked lists.
- The longer list has some extra nodes before the intersection.
- Advance the pointer of the longer list by the difference in lengths.
- Now both pointers have an equal number of nodes left to traverse.
- Move both pointers together until they meet.
- If they meet, return the intersection node; otherwise return NULL.

Algorithm:
1. Find the length of List A and List B.
2. Compute the absolute difference between the lengths.
3. Move the pointer of the longer list ahead by the difference.
4. Traverse both lists simultaneously.
5. Return the first common node if found; otherwise return NULL.

Time Complexity: O(N + M)
Space Complexity: O(1)

Where:
- N = Number of nodes in List A
- M = Number of nodes in List B

================================================================================
*/

class Solution {
public:
    int getLength(ListNode* head) {
        int len = 0;

        while(head != NULL) {
            len++;
            head = head->next;
        }

        return len;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        int lenA = getLength(headA);
        int lenB = getLength(headB);

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        int diff = abs(lenA - lenB);

        if(lenA > lenB) {
            while(diff--) {
                t1 = t1->next;
            }
        }
        else {
            while(diff--) {
                t2 = t2->next;
            }
        }

        while(t1 != NULL && t2 != NULL) {

            if(t1 == t2)
                return t1;

            t1 = t1->next;
            t2 = t2->next;
        }

        return NULL;
    }
};


/*
================================================================================
                    160. Intersection of Two Linked Lists
================================================================================

Problem Link:
https://leetcode.com/problems/intersection-of-two-linked-lists/

Approach: Optimal (Two Pointers)

Intuition:
- Start one pointer at the head of each linked list.
- Traverse both lists simultaneously.
- When a pointer reaches the end of its list, redirect it to the head of the
  other list.
- After switching, both pointers traverse an equal total distance.
- If an intersection exists, they will meet at the first common node.
- Otherwise, both pointers will eventually become NULL at the same time.

Algorithm:
1. Initialize two pointers, one for each linked list.
2. Traverse both lists until the pointers become equal.
3. If a pointer reaches NULL, move it to the head of the other list.
4. Otherwise, move it to the next node.
5. Return the meeting node (or NULL if no intersection exists).

Time Complexity: O(N + M)
Space Complexity: O(1)

Where:
- N = Number of nodes in List A
- M = Number of nodes in List B

================================================================================
*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        while(t1 != t2) {

            if(t1 == NULL)
                t1 = headB;
            else
                t1 = t1->next;

            if(t2 == NULL)
                t2 = headA;
            else
                t2 = t2->next;
        }

        return t1;
    }
};