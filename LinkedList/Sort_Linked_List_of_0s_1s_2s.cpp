/*
================================================================================
Problem: Sort Linked List of 0s, 1s and 2s (Brute Force)

Approach:
1. Traverse the linked list and store all node values in a vector.
2. Sort the vector.
3. Traverse the linked list again and overwrite each node's data
   with the sorted values from the vector.

Time Complexity: O(N log N)
Space Complexity: O(N)

================================================================================
*/

class Solution {
public:
    ListNode* sortList(ListNode* &head) {
        if (head == nullptr) return head;

        vector<int> values;

        ListNode* temp = head;

        // Store all values
        while (temp != nullptr) {
            values.push_back(temp->data);
            temp = temp->next;
        }

        // Sort the values
        sort(values.begin(), values.end());

        // Copy back into linked list
        temp = head;
        int i = 0;

        while (temp != nullptr) {
            temp->data = values[i++];
            temp = temp->next;
        }

        return head;
    }
};


/*
================================================================================
Problem: Sort Linked List of 0s, 1s and 2s (Optimal - Counting)

Approach:
1. Traverse the linked list once and count the number of 0s, 1s, and 2s.
2. Traverse the linked list again:
   - Fill the first cnt0 nodes with 0.
   - Fill the next cnt1 nodes with 1.
   - Fill the remaining nodes with 2.
3. Return the head of the sorted linked list.

Time Complexity: O(N)
Space Complexity: O(1)

================================================================================
*/

class Solution {
public:
    ListNode* sortList(ListNode*& head) {
        if (head == nullptr) return head;

        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        ListNode* temp = head;

        // Count occurrences of 0s, 1s and 2s
        while (temp != nullptr) {
            if (temp->data == 0)
                cnt0++;
            else if (temp->data == 1)
                cnt1++;
            else
                cnt2++;

            temp = temp->next;
        }

        // Overwrite node values in sorted order
        temp = head;

        while (temp != nullptr) {
            if (cnt0 > 0) {
                temp->data = 0;
                cnt0--;
            }
            else if (cnt1 > 0) {
                temp->data = 1;
                cnt1--;
            }
            else {
                temp->data = 2;
                cnt2--;
            }

            temp = temp->next;
        }

        return head;
    }
};


/*
================================================================================
Problem: Sort Linked List of 0s, 1s and 2s (Optimal)

Approach:
1. Create three dummy nodes for lists containing 0s, 1s, and 2s.
2. Traverse the original linked list once:
   - Append each node to its respective list.
3. Connect the three lists:
   - 0s list -> 1s list (if present), otherwise -> 2s list.
   - 1s list -> 2s list.
4. Mark the last node's next as nullptr to avoid cycles.
5. Return the head of the merged list and delete the dummy nodes.

Time Complexity: O(N)
Space Complexity: O(1)

================================================================================
*/

class Solution {
public:
    ListNode* sortList(ListNode*& head) {
        if (head == nullptr) return head;

        ListNode* zeroHead = new ListNode(-1);
        ListNode* oneHead = new ListNode(-1);
        ListNode* twoHead = new ListNode(-1);

        ListNode* zero = zeroHead;
        ListNode* one = oneHead;
        ListNode* two = twoHead;

        ListNode* temp = head;

        // Divide nodes into three separate lists
        while (temp != nullptr) {
            if (temp->data == 0) {
                zero->next = temp;
                zero = zero->next;
            }
            else if (temp->data == 1) {
                one->next = temp;
                one = one->next;
            }
            else {
                two->next = temp;
                two = two->next;
            }

            temp = temp->next;
        }

        // Merge the three lists
        zero->next = (oneHead->next != nullptr) ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;

        ListNode* newHead = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;

        return newHead;
    }
};