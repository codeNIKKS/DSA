#include <bits/stdc++.h>
using namespace std;
/*
========================================
LeetCode 75. Sort Colors
========================================

Approach: Brute Force (Using STL Sort)

Intuition:
Since the array only contains 0s, 1s, and 2s,
we can directly sort the array using the STL sort function.

The sort() function internally uses IntroSort
(Quick Sort + Heap Sort + Insertion Sort)
and sorts the array in non-decreasing order.

Approach:
1. Use sort(nums.begin(), nums.end()).
2. Return the sorted array.

Time Complexity: O(n log n)
Space Complexity: O(log n)

========================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        sort(nums.begin(), nums.end());

    }
};

/*
========================================
LeetCode 75. Sort Colors
========================================

Approach: Better Solution (Counting Method)

Intuition:
The array contains only 0s, 1s, and 2s.

So instead of sorting the array,
we can count the frequency of each element
and then overwrite the array accordingly.

Approach:
1. Count the number of 0s, 1s, and 2s.
2. Fill the array with:
   - all 0s first
   - then all 1s
   - then all 2s

Time Complexity: O(n)
Space Complexity: O(1)

========================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int count0 = 0;
        int count1 = 0;
        int count2 = 0;

        // Counting frequencies
        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 0) {
                count0++;
            }
            else if(nums[i] == 1) {
                count1++;
            }
            else {
                count2++;
            }
        }

        int index = 0;

        // Fill 0s
        while(count0--) {
            nums[index] = 0;
            index++;
        }

        // Fill 1s
        while(count1--) {
            nums[index] = 1;
            index++;
        }

        // Fill 2s
        while(count2--) {
            nums[index] = 2;
            index++;
        }
    }
};


/*
========================================
LeetCode 75. Sort Colors
========================================

Approach: Optimal Solution (Dutch National Flag Algorithm)

Intuition:
Since the array contains only 0s, 1s, and 2s,
we can sort the array in a single traversal
using three pointers.

Pointers Used:
1. low  -> position where next 0 should be placed
2. mid  -> current element being processed
3. high -> position where next 2 should be placed

Algorithm:
1. If nums[mid] == 0
   - swap nums[low] and nums[mid]
   - increment low and mid

2. If nums[mid] == 1
   - mid++

3. If nums[mid] == 2
   - swap nums[mid] and nums[high]
   - decrement high
   - do NOT increment mid because
     the swapped element is still unchecked

Time Complexity: O(n)
Space Complexity: O(1)

========================================
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {

        int low = 0;
        int mid = 0;
        int high = nums.size() - 1;

        while(mid <= high) {

            if(nums[mid] == 0) {

                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }

            else if(nums[mid] == 1) {

                mid++;
            }

            else {

                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};