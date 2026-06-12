/*
    LeetCode 1011. Capacity To Ship Packages Within D Days

    Optimal Approach: Binary Search on Answer

    Intuition:
    - The minimum possible ship capacity is the maximum package weight,
      because every package must be shipped.
    - The maximum possible ship capacity is the sum of all package weights,
      meaning all packages can be shipped in one day.
    - Binary search on this capacity range.
    - For each capacity, calculate how many days are required.
    - If the required days are <= given days, try a smaller capacity.
    - Otherwise, increase the capacity.

    Time Complexity: O(N * log(sum(weights) - max(weights)))
    Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countDays(vector<int>& weights, int capacity) {
        int daysUsed = 1;
        int currentWeight = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (currentWeight + weights[i] > capacity) {
                daysUsed++;
                currentWeight = weights[i];
            } else {
                currentWeight += weights[i];
            }
        }

        return daysUsed;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int daysUsed = countDays(weights, mid);

            if (daysUsed <= days) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};