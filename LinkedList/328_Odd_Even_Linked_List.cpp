/*
=========================================================
LeetCode 328. Odd Even Linked List
Brute Force Approach (Using Extra Array)

Intuition:
- Traverse the linked list and store the values of all odd-indexed nodes.
- Traverse again and store the values of all even-indexed nodes.
- Finally, overwrite the linked list with the stored values in order.
- The node connections remain unchanged; only the values are modified.

Approach:
1. Handle the empty list case.
2. Traverse odd-indexed nodes and store their values.
3. Traverse even-indexed nodes and store their values.
4. Traverse the linked list once more and replace node values using the stored array.
5. Return the head of the modified list.

Time Complexity: O(N)
Space Complexity: O(N)

=========================================================
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr)
            return head;

        vector<int> arr;

        ListNode* temp = head;

        // Store odd indexed node values
        while(temp != nullptr && temp->next != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        if(temp != nullptr)
            arr.push_back(temp->val);

        // Store even indexed node values
        temp = head->next;

        while(temp != nullptr && temp->next != nullptr) {
            arr.push_back(temp->val);
            temp = temp->next->next;
        }

        if(temp != nullptr)
            arr.push_back(temp->val);

        // Copy values back into the linked list
        temp = head;
        int i = 0;

        while(temp != nullptr) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};
```


/*
=========================================================
LeetCode 328. Odd Even Linked List
Optimal Approach (Rearranging Links)

Intuition:
- Maintain two separate chains:
  1. Odd-indexed nodes
  2. Even-indexed nodes
- Traverse the list once, reconnecting odd nodes together and even nodes together.
- Finally, attach the even list to the end of the odd list.
- This rearranges the existing nodes without using any extra space.

Approach:
1. Handle the edge cases of an empty list or a single-node list.
2. Initialize:
   - odd = head
   - even = head->next
   - evenHead = head->next (to remember the start of the even list)
3. While both even and even->next exist:
   - Connect the current odd node to the next odd node.
   - Connect the current even node to the next even node.
   - Move both pointers forward.
4. Attach the even list after the last odd node.
5. Return the head.

Time Complexity: O(N)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next;

        while(even != nullptr && even->next != nullptr) {
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};