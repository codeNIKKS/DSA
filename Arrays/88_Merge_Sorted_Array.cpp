/*
=========================================================
LeetCode 88. Merge Sorted Array
Approach: Brute Force (Copy + Sort)

Intuition:
- nums1 has extra space at the end to accommodate all elements of nums2.
- Copy all elements of nums2 into the vacant positions of nums1.
- Sort the entire nums1 array.
- The sorted array is the required merged result.

Approach:
1. Copy nums2[i] into nums1[m + i].
2. Sort nums1 from beginning to end.
3. nums1 now contains all elements in sorted order.

Time Complexity: O((m + n) log(m + n))
Space Complexity: O(1)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        for(int i = 0; i < n; i++) {
            nums1[m + i] = nums2[i];
        }

        sort(nums1.begin(), nums1.end());
    }
};


/*
=========================================================
LeetCode 88. Merge Sorted Array
Approach: Optimal (Three Pointers from Back)

Intuition:
- nums1 already has enough space to store all elements.
- If we start merging from the front, elements of nums1 may get overwritten.
- To avoid shifting elements, start filling nums1 from the end.
- Compare the largest remaining elements of nums1 and nums2.
- Place the larger one at the last available position.
- Continue until all elements are merged.

Approach:
1. Initialize:
   - i = m - 1  -> last valid element in nums1
   - j = n - 1  -> last element in nums2
   - k = m + n - 1 -> last position in nums1

2. Compare nums1[i] and nums2[j]:
   - Place the larger element at nums1[k].
   - Move the corresponding pointer.

3. After one array is exhausted:
   - Copy remaining elements of nums2 (if any).
   - Remaining elements of nums1 are already in correct positions.

Time Complexity: O(m + n)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while(i >= 0 && j >= 0) {

            if(nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            }
            else {
                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }

        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
    }
};