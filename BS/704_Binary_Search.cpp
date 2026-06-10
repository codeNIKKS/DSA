/*
=========================================================
🔍 Problem: Search X in Sorted Array
=========================================================

Given a sorted array and a target value, return the index
of the target if it exists, otherwise return -1.

---------------------------------------------------------
💡 Intuition
---------------------------------------------------------
Since the array is sorted, checking every element one by
one is unnecessary. We can use Binary Search to eliminate
half of the search space after every comparison.

At each step:
1. Find the middle element.
2. If middle element equals target → return index.
3. If target is greater → search right half.
4. Otherwise → search left half.

This divide-and-conquer approach reduces the search space
from N to N/2 in every step.

---------------------------------------------------------
🚀 Approach (Recursive Binary Search)
---------------------------------------------------------
1. Define a recursive function:
      f(arr, low, high, target)

2. Base Case:
      If low > high, target is not present.
      Return -1.

3. Find middle index:
      mid = low + (high - low) / 2

4. Compare:
      arr[mid] == target  → return mid
      target > arr[mid]   → search right half
      otherwise           → search left half

5. Return the result obtained from recursion.

---------------------------------------------------------
⏱️ Complexity Analysis
---------------------------------------------------------
Time Complexity  : O(log N)
Space Complexity : O(log N)   (Recursion Stack)

---------------------------------------------------------
✅ Key Learning
---------------------------------------------------------
- Binary Search requires a sorted array.
- Always use:
      low + (high - low) / 2
  to avoid integer overflow.
- Recursive Binary Search uses O(log N) stack space.
- Iterative Binary Search is generally preferred in
  interviews because it uses O(1) extra space.

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(vector<int>& arr, int low, int high, int target) {

        if (low > high) return -1;

        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (target > arr[mid]) {
            return f(arr, mid + 1, high, target);
        }
        else {
            return f(arr, low, mid - 1, target);
        }
    }

    int search(vector<int>& nums, int target) {
        return f(nums, 0, nums.size() - 1, target);
    }
};


/*
=========================================================
🔍 Problem: Search X in Sorted Array
=========================================================

Given a sorted array and a target value, return the index
of the target if it exists, otherwise return -1.

---------------------------------------------------------
💡 Intuition
---------------------------------------------------------
The array is already sorted, which allows us to eliminate
half of the search space after every comparison.

Instead of checking each element one by one, we compare
the target with the middle element:

• If target == nums[mid] → answer found.
• If target > nums[mid]  → search right half.
• If target < nums[mid]  → search left half.

By repeatedly discarding half of the array, we achieve
a logarithmic time complexity.

---------------------------------------------------------
🚀 Approach (Iterative Binary Search)
---------------------------------------------------------
1. Initialize:
      low = 0
      high = n - 1

2. While low <= high:
      mid = low + (high - low) / 2

3. Compare:
      nums[mid] == target → return mid
      nums[mid] < target  → search right half
      nums[mid] > target  → search left half

4. If loop ends, target is not present.
   Return -1.

---------------------------------------------------------
⏱️ Complexity Analysis
---------------------------------------------------------
Time Complexity  : O(log N)

Space Complexity : O(1)

---------------------------------------------------------
✅ Why This Is Optimal
---------------------------------------------------------
- Linear Search takes O(N).
- Binary Search reduces the search space by half at
  every step.
- No extra data structures are used.
- Achieves the best possible time complexity for
  searching in a sorted array.

---------------------------------------------------------
📌 Key Learning
---------------------------------------------------------
- Binary Search works only on sorted data.
- Use:
      low + (high - low) / 2
  instead of:
      (low + high) / 2
  to avoid integer overflow.
- Iterative Binary Search is preferred over recursive
  Binary Search because it uses O(1) extra space.

=========================================================
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {

            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return -1;
    }
};