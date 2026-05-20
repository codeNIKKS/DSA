#include <bits/stdc++.h>
using namespace std;
/*
    LeetCode 485. Maximum Consecutive Ones

    Approach:
    ----------
    This approach uses two pointers to find consecutive blocks of 1s.

    -> First pointer 'i' skips all 0s and stops at the first 1.
    -> Second pointer 'j' moves until a 0 is found.
    -> Length of current consecutive 1s block = j - i.
    -> Update maximum count accordingly.

    Although this approach works in O(n),
    it is slightly more complex than the optimal counting approach.

    Time Complexity  : O(n)
    Space Complexity : O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();

        int i = 0;
        int j = 0;

        int maxcount = 0;

        while(i < n) {

            int count = 0;

            // Skip all 0s
            while(i < n && nums[i] != 1) {
                i++;
            }

            // Start j from current i
            if(j <= i) {
                j = i;
            }

            // Traverse consecutive 1s
            while(j < n && nums[j] != 0) {
                j++;
            }

            // Length of current block of 1s
            count = j - i;

            // Update answer
            maxcount = max(count, maxcount);

            // Move i forward
            i = j;
        }

        return maxcount;
    }
};

/*
    LeetCode 485. Maximum Consecutive Ones

    Optimal Approach:
    ------------------
    Traverse the array once while maintaining a counter
    for consecutive 1s.

    -> If current element is 1:
       increment count.

    -> If current element is 0:
       reset count to 0.

    -> Continuously update maximum count.

    This is the simplest and most efficient solution.

    Time Complexity  : O(n)
    Space Complexity : O(1)
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count = 0;
        int maxcount = 0;

        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] == 1) {
                count++;
            }
            else {
                count = 0;
            }

            maxcount = max(count, maxcount);
        }

        return maxcount;
    }
};