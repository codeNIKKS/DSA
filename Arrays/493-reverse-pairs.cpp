/*
=========================================================
Reverse Pairs (Brute Force)

Problem:
Given an integer array nums, return the number of reverse
pairs where:
i < j and nums[i] > 2 * nums[j]

Intuition:
- Check every possible pair (i, j).
- If nums[i] > 2 * nums[j], count it.

Approach:
1. Use two nested loops.
2. For each pair (i, j), verify the condition.
3. Count all valid reverse pairs.

Time Complexity: O(n²)
Space Complexity: O(1)
=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((long long)nums[i] > 2LL * nums[j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};


/*
=========================================================
Reverse Pairs (Optimal - Merge Sort)

Problem:
Given an integer array nums, return the number of reverse
pairs where:
i < j and nums[i] > 2 * nums[j]

Intuition:
- While performing Merge Sort, both halves become sorted.
- For each element in the left half, count how many
  elements in the right half satisfy:
      nums[i] > 2 * nums[j]
- Use a moving pointer to achieve O(n) counting
  per merge step.

Approach:
1. Divide the array using Merge Sort.
2. Count reverse pairs in left half.
3. Count reverse pairs in right half.
4. Count cross-half reverse pairs.
5. Merge the sorted halves.

Time Complexity: O(n log n)
Space Complexity: O(n)
=========================================================
*/

class Solution {
public:
    void merge(vector<int>& arr, int low, int mid, int high) {
        vector<int> temp;

        int left = low;
        int right = mid + 1;

        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            } else {
                temp.push_back(arr[right]);
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
    }

    int countPairs(vector<int>& arr, int low, int mid, int high) {
        int cnt = 0;
        int right = mid + 1;

        for (int i = low; i <= mid; i++) {
            while (right <= high &&
                   (long long)arr[i] > 2LL * arr[right]) {
                right++;
            }

            cnt += right - (mid + 1);
        }

        return cnt;
    }

    int mergeSort(vector<int>& arr, int low, int high) {
        if (low >= high) return 0;

        int mid = low + (high - low) / 2;

        int cnt = 0;

        cnt += mergeSort(arr, low, mid);
        cnt += mergeSort(arr, mid + 1, high);

        cnt += countPairs(arr, low, mid, high);

        merge(arr, low, mid, high);

        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
};