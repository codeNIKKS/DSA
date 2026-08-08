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

Approach : Optimal (Interweaving / In-Place Copy)

Intuition:
- Instead of using a hash map, insert each copied node immediately
  after its original node.
- This allows direct access to the copied version of any node using
  original->next.
- Assign random pointers using:
      copy->random = original->random->next
- Finally, separate the interleaved list into the original list
  and the copied list.

Time Complexity : O(N)
Space Complexity: O(1)   (excluding the copied list)

----------------------------------------------------------------------------
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if (head == NULL)
            return NULL;

        Node* temp = head;

        // Step 1: Insert copied nodes after every original node
        while (temp != NULL) {

            Node* copyNode = new Node(temp->val);

            copyNode->next = temp->next;
            temp->next = copyNode;

            temp = copyNode->next;
        }

        temp = head;

        // Step 2: Copy random pointers
        while (temp != NULL) {

            if (temp->random != NULL)
                temp->next->random = temp->random->next;

            temp = temp->next->next;
        }

        temp = head;

        // Step 3: Separate the original and copied lists
        Node* dummy = new Node(-1);
        Node* copyTail = dummy;

        while (temp != NULL) {

            Node* copyNode = temp->next;

            // Restore original list
            temp->next = copyNode->next;

            // Append copied node to cloned list
            copyTail->next = copyNode;
            copyTail = copyTail->next;

            temp = temp->next;
        }

        Node* copyHead = dummy->next;
        delete dummy;

        return copyHead;
    }
};