/*
    LeetCode 2149 - Rearrange Array Elements by Sign
    Brute Force Approach

    Intuition:
    - Store all positive numbers in one array.
    - Store all negative numbers in another array.
    - Place positive numbers at even indices
      and negative numbers at odd indices.

    Approach:
    1. Traverse nums and separate positives and negatives.
    2. Traverse again and fill nums alternatively:
       - even index -> positive
       - odd index  -> negative

    Time Complexity: O(n)
    Space Complexity: O(n)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> pos;
        vector<int> neg;

        // Store positive and negative numbers separately
        for(int i = 0; i < n; i++) {

            if(nums[i] > 0) {
                pos.push_back(nums[i]);
            }
            else {
                neg.push_back(nums[i]);
            }
        }

        // Rearrange alternatively
        for(int i = 0; i < n; i++) {

            if(i % 2 == 0) {
                nums[i] = pos[i / 2];
            }
            else {
                nums[i] = neg[i / 2];
            }
        }

        return nums;
    }
};


/*
    LeetCode 2149 - Rearrange Array Elements by Sign
    Optimal Approach

    Intuition:
    - The problem guarantees:
        1. Equal number of positive and negative integers.
        2. Rearranged array starts with a positive integer.

    - So:
        * Positive numbers will always be placed at:
            0, 2, 4, 6...
        * Negative numbers will always be placed at:
            1, 3, 5, 7...

    Approach:
    1. Create an answer array of size n.
    2. Maintain:
        - pos pointer for even indices
        - neg pointer for odd indices
    3. Traverse nums:
        - If positive -> place at pos index
        - If negative -> place at neg index
    4. Move pointers by 2 each time.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n = nums.size();

        int pos = 0;
        int neg = 1;

        vector<int> ans(n);

        for(int i = 0; i < n; i++) {

            if(nums[i] > 0) {

                ans[pos] = nums[i];
                pos += 2;
            }
            else {

                ans[neg] = nums[i];
                neg += 2;
            }
        }

        return ans;
    }
};