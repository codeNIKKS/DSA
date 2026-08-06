/*
================================================================================
                                LeetCode 148. Sort List
================================================================================

Approach : Brute Force (Store Values in Array + Sort + Rewrite List)

Intuition:
- Traverse the linked list and store all node values in a vector.
- Sort the vector.
- Traverse the linked list again and overwrite each node's value
  using the sorted vector.
- The linked list becomes sorted without changing its structure.

Algorithm:
1. Traverse the linked list and push every node value into a vector.
2. Sort the vector.
3. Traverse the linked list again.
4. Replace each node's value with the corresponding sorted value.
5. Return the head.

Time Complexity : O(n log n)
Space Complexity: O(n)

================================================================================
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        vector<int> arr;

        ListNode* temp = head;

        while(temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        temp = head;
        int i = 0;

        while(temp != NULL) {
            temp->val = arr[i++];
            temp = temp->next;
        }

        return head;
    }
};


/*
================================================================================
                            LeetCode 148. Sort List
================================================================================

Approach : Optimal (Merge Sort on Linked List)

Intuition:
- Unlike arrays, linked lists do not support random access, making algorithms
  like Quick Sort inefficient.
- Merge Sort is the ideal sorting algorithm for linked lists because:
    * Finding the middle can be done using Slow & Fast pointers.
    * Merging two sorted linked lists can be done in linear time.
    * No extra array is required.
- Recursively split the list into two halves until each sublist contains a
  single node, then merge the sorted halves.

Algorithm:
1. If the list has 0 or 1 node, it is already sorted.
2. Find the middle node using Slow & Fast pointers.
3. Split the linked list into two halves.
4. Recursively sort both halves.
5. Merge the two sorted linked lists.
6. Return the head of the merged list.

Time Complexity : O(n log n)
Space Complexity: O(log n)     // Recursion stack

================================================================================
*/

class Solution {
public:

    ListNode* merge2list(ListNode* list1, ListNode* list2) {

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while(temp1 != NULL && temp2 != NULL) {

            if(temp1->val <= temp2->val) {
                tail->next = temp1;
                temp1 = temp1->next;
            }
            else {
                tail->next = temp2;
                temp2 = temp2->next;
            }

            tail = tail->next;
        }

        if(temp1 != NULL)
            tail->next = temp1;
        else
            tail->next = temp2;

        ListNode* head = dummy->next;
        delete dummy;

        return head;
    }

    ListNode* findMiddle(ListNode* head) {

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* mergeSort(ListNode* head) {

        if(head == NULL || head->next == NULL)
            return head;

        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;

        middle->next = NULL;

        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);

        return merge2list(leftHead, rightHead);
    }

    ListNode* sortList(ListNode* head) {

        return mergeSort(head);
    }
};