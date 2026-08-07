/*
-------------------------------------------------------
Problem: Flatten Linked List
Approach: Brute Force (Store Values + Sort + Create New List)

Intuition:
- Traverse every linked list using the 'next' and 'child' pointers.
- Store all node values in a vector.
- Sort the vector.
- Create a new flattened linked list using the sorted values.
- Connect the new list using the 'child' pointer.

Algorithm:
1. Traverse every vertical linked list and store all values.
2. Sort the collected values.
3. Create a new linked list from the sorted values.
4. Return the head of the new list.

Time Complexity: O(M log M)
- M = Total number of nodes.
- O(M) for traversal.
- O(M log M) for sorting.
- O(M) for creating the new linked list.

Space Complexity: O(M)
- Vector to store all node values.
- New linked list is also created.

-------------------------------------------------------
*/

class Solution {
public:

    // Creates a new sorted child linked list from the vector
    ListNode* buildList(vector<int>& arr) {

        if (arr.empty())
            return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for (int i = 1; i < arr.size(); i++) {

            ListNode* newNode = new ListNode(arr[i]);

            temp->child = newNode;
            temp = temp->child;

            temp->next = NULL;
        }

        return head;
    }

    ListNode* flattenLinkedList(ListNode* head) {

        vector<int> arr;

        ListNode* curr = head;

        // Traverse every linked list
        while (curr != NULL) {

            ListNode* down = curr;

            while (down != NULL) {
                arr.push_back(down->val);
                down = down->child;
            }

            curr = curr->next;
        }

        // Sort all values
        sort(arr.begin(), arr.end());

        // Build a new flattened linked list
        return buildList(arr);
    }
};


/*
-------------------------------------------------------
Problem: Flatten Linked List
Approach: Optimal (Recursion + Merge Two Sorted Linked Lists)

Intuition:
- Every vertical linked list connected using the 'child' pointer is already sorted.
- Recursively flatten the linked list on the right.
- Merge the current sorted child list with the already flattened sorted list.
- This is similar to the Merge Sort technique, where two sorted lists are merged at each step.

Algorithm:
1. If the current head is NULL or there is only one linked list, return it.
2. Recursively flatten the remaining linked lists.
3. Merge the current child list with the flattened child list.
4. Return the head of the merged linked list.

Time Complexity: O(N × M)
- N = Number of linked lists (head nodes connected using next).
- M = Total number of nodes.

Space Complexity: O(N)
- Recursive call stack.

-------------------------------------------------------
*/

class Solution {
public:

    // Merge two sorted child linked lists
    ListNode* merge(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (list1 != NULL && list2 != NULL) {

            if (list1->val <= list2->val) {
                tail->child = list1;
                tail = list1;
                list1 = list1->child;
            }
            else {
                tail->child = list2;
                tail = list2;
                list2 = list2->child;
            }

            // Remove old horizontal link
            tail->next = NULL;
        }

        if (list1)
            tail->child = list1;
        else
            tail->child = list2;

        ListNode* head = dummy->child;
        delete dummy;

        return head;
    }

    ListNode* flattenLinkedList(ListNode* head) {

        // Base Case
        if (head == NULL || head->next == NULL)
            return head;

        // Flatten the remaining linked lists
        ListNode* mergedHead = flattenLinkedList(head->next);

        // Merge the current list with the flattened list
        head = merge(head, mergedHead);

        return head;
    }
};