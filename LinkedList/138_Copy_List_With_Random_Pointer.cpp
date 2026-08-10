/*
----------------------------------------------------------------------------
Problem : 138. Copy List with Random Pointer
Link    : https://leetcode.com/problems/copy-list-with-random-pointer/

Approach : Brute Force (Hash Map)

Intuition:
- Create a copy of every original node and store the mapping:
      Original Node -> Copied Node.
- Traverse the original list again and use the map to connect
  the next and random pointers of each copied node.
- Finally, return the copied head stored in the map.

Time Complexity : O(N)
Space Complexity: O(N)

----------------------------------------------------------------------------
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        unordered_map<Node*, Node*> mpp;

        Node* temp = head;

        // Step 1: Create a copy of every node
        while (temp != NULL) {
            mpp[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;

        // Step 2: Connect next and random pointers
        while (temp != NULL) {

            Node* copyNode = mpp[temp];

            copyNode->next =
                (temp->next != NULL) ? mpp[temp->next] : NULL;

            copyNode->random =
                (temp->random != NULL) ? mpp[temp->random] : NULL;

            temp = temp->next;
        }

        return mpp[head];
    }
};


/*
----------------------------------------------------------------------------
Problem : 138. Copy List with Random Pointer
Link    : https://leetcode.com/problems/copy-list-with-random-pointer/

Approach : Optimal - Interweaving / In-Place Copy

Intuition:
- Create a copy of every node and insert it immediately after its
  corresponding original node.
- This gives us direct access to the copy of any node using:
      original->next
- For the random pointer, if:
      temp->random = X
  then:
      temp->random->next
  is the copy of X.
- Finally, separate the original and copied lists.

Steps:
1. Create and interleave copied nodes.
2. Assign random pointers of copied nodes.
3. Separate the original and copied linked lists.

Time Complexity : O(N)
Space Complexity: O(1) auxiliary space

----------------------------------------------------------------------------
*/

class Solution {
public:
    ListNode* copyRandomList(ListNode* head) {

        if (head == NULL)
            return NULL;

        ListNode* temp = head;

        // Step 1: Create and interleave copied nodes
        while (temp != NULL) {

            ListNode* copyNode = new ListNode(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;
        }

        // Step 2: Assign random pointers
        temp = head;

        while (temp != NULL) {

            ListNode* copyNode = temp->next;

            if (temp->random != NULL)
                copyNode->random = temp->random->next;
            else
                copyNode->random = NULL;

            temp = temp->next->next;
        }

        // Step 3: Separate original and copied lists
        ListNode* dummy = new ListNode(-1);
        ListNode* res = dummy;

        temp = head;

        while (temp != NULL) {

            res->next = temp->next;

            // Restore original list
            temp->next = temp->next->next;

            // Move copied-list pointer
            res = res->next;

            // Move original-list pointer
            temp = temp->next;
        }

        ListNode* copyHead = dummy->next;
        delete dummy;

        return copyHead;
    }
};