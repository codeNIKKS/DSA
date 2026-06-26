/*
=========================================================
  Problem: Add One to Number Represented by Linked List
  Approach: Reverse Linked List
=========================================================

Intuition:
- Adding 1 starts from the least significant digit, but in a singly
  linked list we only have access from the most significant digit.
- Reverse the linked list so that the last digit becomes the first.
- Add the carry (initially 1) just like elementary addition.
- If a node becomes 10, set it to 0 and propagate the carry.
- If carry still exists after the last node, append a new node with value 0
  (which will become 1 after reversing back).
- Finally, reverse the list again to restore the original order.

Approach:
1. Reverse the linked list.
2. Initialize carry = 1.
3. Traverse the reversed list:
   - Add carry to current node.
   - If value < 10, carry becomes 0.
   - Otherwise, set node value to 0 and continue with carry = 1.
4. If carry reaches the last node, create a new node.
5. Reverse the list again and return the head.

Time Complexity: O(N)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* addOne(ListNode* head) {
        head = reverse(head);

        ListNode* temp = head;
        int carry = 1;

        while (temp && carry) {
            temp->val += carry;

            if (temp->val < 10) {
                carry = 0;
            } else {
                temp->val = 0;
                carry = 1;
            }

            if (carry && temp->next == NULL) {
                temp->next = new ListNode(0);
            }

            temp = temp->next;
        }

        return reverse(head);
    }
};


/*
=========================================================
  Problem: Add One to Number Represented by Linked List
  Approach: Recursion
=========================================================

Intuition:
- Addition starts from the least significant digit, which is the last
  node of the linked list.
- Since a singly linked list cannot be traversed backwards, recursion
  is used to reach the last node first.
- The base case returns a carry of 1, representing the '+1' operation.
- While returning from recursion, each node adds the carry, updates
  its value, and generates a new carry if needed.
- If a carry still remains after processing the head, create a new
  node with value 1 and make it the new head.

Approach:
1. Recursively reach the last node.
2. Base case returns carry = 1.
3. While backtracking:
   - Add carry to current node.
   - If value < 10, return carry = 0.
   - Otherwise, set value to 0 and return carry = 1.
4. After recursion finishes, if carry still exists, create a new head
   with value 1.
5. Return the updated head.

Time Complexity: O(N)
Space Complexity: O(N)   // Recursion stack

=========================================================
*/

class Solution {
public:
    int helper(ListNode* node) {
        if (node == NULL)
            return 1;

        int carry = helper(node->next);

        node->val += carry;

        if (node->val < 10)
            return 0;

        node->val = 0;
        return 1;
    }

    ListNode* addOne(ListNode* head) {
        int carry = helper(head);

        if (carry) {
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            head = newHead;
        }

        return head;
    }
};
```