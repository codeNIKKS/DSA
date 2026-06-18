/*
=========================================================
LeetCode 4. Median of Two Sorted Arrays
=========================================================

Problem:
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

---------------------------------------------------------
Brute Force Approach
---------------------------------------------------------
Intuition:
Merge both sorted arrays into a single sorted array and then
find the median from the merged array.

Approach:
1. Create a new array merged.
2. Use two pointers to merge nums1 and nums2.
3. If total length is odd:
      median = merged[n/2]
4. If total length is even:
      median = (merged[n/2 - 1] + merged[n/2]) / 2

Time Complexity: O(m + n)
Space Complexity: O(m + n)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        vector<int> merged;

        int i = 0, j = 0;

        while(i < n1 && j < n2) {
            if(nums1[i] <= nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            }
            else {
                merged.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n1) {
            merged.push_back(nums1[i]);
            i++;
        }

        while(j < n2) {
            merged.push_back(nums2[j]);
            j++;
        }

        int n = merged.size();

        if(n % 2 == 1) {
            return merged[n / 2];
        }

        return ((double)merged[n / 2] + merged[(n / 2) - 1]) / 2.0;
    }
};


/*
=========================================================
LeetCode 4. Median of Two Sorted Arrays
=========================================================

Problem:
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

---------------------------------------------------------
Better Approach
---------------------------------------------------------
Intuition:
Since both arrays are already sorted, we do not need to
create the entire merged array.

While performing the merge process, we only keep track of
the two middle elements required to calculate the median.

Approach:
1. Calculate:
      ind2 = (n1 + n2) / 2
      ind1 = ind2 - 1
2. Perform the merge process using two pointers.
3. Whenever the current merged index reaches ind1 or ind2,
   store the corresponding element.
4. For:
      Odd length  -> return element at ind2.
      Even length -> return average of elements at
                     ind1 and ind2.

Time Complexity: O(m + n)
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        int n = n1 + n2;

        int ind2 = n / 2;
        int ind1 = ind2 - 1;

        int cnt = 0;
        int el1 = -1, el2 = -1;

        int i = 0, j = 0;

        while(i < n1 && j < n2) {

            if(nums1[i] <= nums2[j]) {

                if(cnt == ind1) el1 = nums1[i];
                if(cnt == ind2) el2 = nums1[i];

                cnt++;
                i++;
            }
            else {

                if(cnt == ind1) el1 = nums2[j];
                if(cnt == ind2) el2 = nums2[j];

                cnt++;
                j++;
            }
        }

        while(i < n1) {

            if(cnt == ind1) el1 = nums1[i];
            if(cnt == ind2) el2 = nums1[i];

            cnt++;
            i++;
        }

        while(j < n2) {

            if(cnt == ind1) el1 = nums2[j];
            if(cnt == ind2) el2 = nums2[j];

            cnt++;
            j++;
        }

        if(n % 2 == 1) {
            return el2;
        }

        return ((double)el1 + el2) / 2.0;
    }
};


/*
=========================================================
LeetCode 4. Median of Two Sorted Arrays
=========================================================

Problem:
Given two sorted arrays nums1 and nums2 of size m and n respectively,
return the median of the two sorted arrays.

---------------------------------------------------------
Optimal Approach (Binary Search on Partition)
---------------------------------------------------------
Intuition:
Instead of merging the arrays, partition both arrays such
that:

    Left Half Size = Right Half Size
    All elements in Left Half <= All elements in Right Half

Since both arrays are sorted, we only need to check the
boundary elements of the partitions.

To minimize the search space, always perform binary search
on the smaller array.

Partition Conditions:
    l1 <= r2
    l2 <= r1

If both conditions are satisfied:
    - Odd length  -> median = max(l1, l2)
    - Even length -> median =
                     (max(l1,l2) + min(r1,r2))/2

---------------------------------------------------------
Approach:
1. Ensure nums1 is the smaller array.
2. Binary search on nums1.
3. Compute partition positions:
       mid1 = partition in nums1
       mid2 = leftHalfSize - mid1
4. Determine:
       l1, r1, l2, r2
5. Check partition validity.
6. Return median when valid.
7. Otherwise move left/right accordingly.

Time Complexity: O(log(min(m, n)))
Space Complexity: O(1)

=========================================================
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int n1 = nums1.size();
        int n2 = nums2.size();

        if(n1 > n2)
            return findMedianSortedArrays(nums2, nums1);

        int low = 0;
        int high = n1;

        int n = n1 + n2;
        int left = (n + 1) / 2;

        while(low <= high) {

            int mid1 = low + (high - low) / 2;
            int mid2 = left - mid1;

            int l1 = (mid1 > 0) ? nums1[mid1 - 1] : INT_MIN;
            int r1 = (mid1 < n1) ? nums1[mid1] : INT_MAX;

            int l2 = (mid2 > 0) ? nums2[mid2 - 1] : INT_MIN;
            int r2 = (mid2 < n2) ? nums2[mid2] : INT_MAX;

            if(l1 <= r2 && l2 <= r1) {

                if(n % 2 == 1) {
                    return max(l1, l2);
                }

                return ((double)max(l1, l2) +
                        min(r1, r2)) / 2.0;
            }
            else if(l1 > r2) {
                high = mid1 - 1;
            }
            else {
                low = mid1 + 1;
            }
        }

        return 0.0;
    }
};