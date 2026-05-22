/*
=========================================================
121. Best Time to Buy and Sell Stock (Brute Force)
=========================================================

Problem:
Given an array where arr[i] represents the stock price
on the ith day, find the maximum profit possible by
buying once and selling once.

---------------------------------------------------------
Intuition:
Try every possible buying day and compare it with every
future selling day.

For each pair:
profit = selling price - buying price

Store the maximum profit obtained.

---------------------------------------------------------
Approach:
1. Pick each day as buying day using outer loop.
2. Check all future days as selling days.
3. Calculate profit for every pair.
4. Update maximum profit.

---------------------------------------------------------
Time Complexity:
O(n^2)

Space Complexity:
O(1)

=========================================================
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int stockBuySell(vector<int> arr, int n) {

        int maxprofit = 0;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                int profit = arr[j] - arr[i];

                maxprofit = max(maxprofit, profit);
            }
        }

        return maxprofit;
    }
};


/*
=========================================================
121. Best Time to Buy and Sell Stock (Optimal Approach)
=========================================================

Problem:
Given an array where arr[i] represents the stock price
on the ith day, find the maximum profit possible by
buying once and selling once.

---------------------------------------------------------
Intuition:
To get maximum profit on any day, we should have bought
the stock at the minimum price seen before that day.

So while traversing the array:
- Keep track of minimum price till now.
- Calculate profit if sold today.
- Update maximum profit.

---------------------------------------------------------
Approach:
1. Initialize:
   - mini = INT_MAX
   - maxprofit = 0

2. Traverse the array:
   - Update minimum price seen so far.
   - Calculate:
       profit = current price - minimum price
   - Update maximum profit.

3. Return maximum profit.

---------------------------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(1)

=========================================================
*/

class Solution {
public:
    int stockBuySell(vector<int> arr, int n) {

        int mini = INT_MAX;
        int maxprofit = 0;

        for(int i = 0; i < n; i++) {

            mini = min(arr[i], mini);

            int profit = arr[i] - mini;

            maxprofit = max(maxprofit, profit);
        }

        return maxprofit;
    }
};