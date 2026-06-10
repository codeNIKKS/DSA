/*
=========================================
Problem: Count Inversions
Approach: Brute Force (Two Nested Loops)
=========================================

Intuition:
- An inversion is a pair (i, j) such that:
      i < j
      arr[i] > arr[j]
- Check every possible pair in the array.
- If the pair forms an inversion, increment the count.

Algorithm:
1. Initialize inversion count = 0.
2. Traverse all pairs using two loops:
      i from 0 to n-1
      j from i+1 to n-1
3. If arr[i] > arr[j], increment count.
4. Return count.

Time Complexity:
- O(N²)
  (Checking all possible pairs)

Space Complexity:
- O(1)

Note:
- Use long long because the number of inversions
  can be as large as N*(N-1)/2.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long int numberOfInversions(vector<int> nums) {
        int n = nums.size();
        long long cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(nums[i] > nums[j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


/*
====================================================
Problem: Count Inversions
Approach: Merge Sort + Counting During Merge
====================================================

Intuition:
- An inversion is a pair (i, j) such that:
      i < j
      arr[i] > arr[j]

- Brute force checks every pair in O(N²).

- While merging two sorted halves:
      Left  = [low ... mid]
      Right = [mid+1 ... high]

- If:
      arr[left] <= arr[right]
  then no inversion exists.

- Else:
      arr[left] > arr[right]

  Since the left half is already sorted,
  every element from 'left' to 'mid'
  will also be greater than arr[right].

  Therefore, inversions added:

      (mid - left + 1)

Example:
      Left  = [4, 5, 6]
      Right = [2]

      4 > 2
      5 > 2
      6 > 2

      Inversions = 3

Algorithm:
1. Divide array using Merge Sort.
2. Recursively count inversions in left half.
3. Recursively count inversions in right half.
4. Count cross inversions during merge.
5. Return total count.

Time Complexity:
- O(N log N)

Space Complexity:
- O(N)
  (Temporary array used during merge)
*/

class Solution {
public:
    long long merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        long long cnt = 0;

        while (left <= mid && right <= high) {

            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);

                // Count inversions
                cnt += (mid - left + 1);

                right++;
            }
        }

        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }

        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }

        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }

        return cnt;
    }

    long long mergeSort(vector<int>& arr, int low, int high) {

        if (low >= high)
            return 0;

        int mid = low + (high - low) / 2;

        long long cnt = 0;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);
        cnt += merge(arr, low, mid, high);

        return cnt;
    }

    long long int numberOfInversions(vector<int> nums) {

        int n = nums.size();

        return mergeSort(nums, 0, n - 1);
    }
};