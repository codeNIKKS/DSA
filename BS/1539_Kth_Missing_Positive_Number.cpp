/*
-------------------------------------------------------
Problem: Kth Missing Positive Number
Approach: Binary Search (Optimal)
Time Complexity: O(log n)
Space Complexity: O(1)
-------------------------------------------------------

Intuition:
For any index i,

missingCount = arr[i] - (i + 1)

This represents how many positive integers are missing
before arr[i].

Since missingCount is monotonically increasing,
we can Binary Search for the first index where:

missingCount >= k

After the search:
low = first index with missingCount >= k

Answer = low + k
-------------------------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low + k;
    }
};