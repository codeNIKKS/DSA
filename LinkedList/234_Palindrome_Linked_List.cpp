/*
=========================================================
|  Problem: 234. Palindrome Linked List
|  Approach: Brute Force (Using Stack)
|
|  Intuition:
|  - A stack follows the LIFO (Last In, First Out) principle.
|  - Traverse the linked list once and push every node's value
|    into the stack.
|  - Traverse the list again from the head.
|  - At each step, compare the current node's value with the
|    top element of the stack.
|  - If any value differs, the list is not a palindrome.
|  - If all values match, the linked list is a palindrome.
|
|  Time Complexity: O(n)
|  Space Complexity: O(n)
=========================================================
*/

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        // Store all node values in the stack
        while (temp != nullptr) {
            st.push(temp->val);
            temp = temp->next;
        }

        // Compare stack values with linked list
        temp = head;
        while (temp != nullptr) {
            if (temp->val != st.top())
                return false;

            st.pop();
            temp = temp->next;
        }

        return true;
    }
};


/*
=========================================================
|  Problem: 234. Palindrome Linked List
|  Approach: Optimal (Reverse Second Half)
|
|  Intuition:
|  - Use the slow and fast pointer technique to find the
|    middle of the linked list.
|  - Reverse the second half of the linked list.
|  - Compare the first half and the reversed second half
|    node by node.
|  - If any pair of values differs, the list is not a
|    palindrome.
|  - Restore the original linked list by reversing the
|    second half again before returning.
|
|  Time Complexity: O(n)
|  Space Complexity: O(1)
=========================================================
*/

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return true;

        // Find the end of the first half
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next != nullptr && fast->next->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse the second half
        ListNode* secondHead = reverse(slow->next);

        // Compare both halves
        ListNode* first = head;
        ListNode* second = secondHead;

        while (second != nullptr) {
            if (first->val != second->val) {
                reverse(secondHead);   // Restore the list
                return false;
            }

            first = first->next;
            second = second->next;
        }

        // Restore the original list
        reverse(secondHead);

        return true;
    }
};