/*
    Problem: Maximum Product Subarray
    LeetCode: 152

    Intuition:
    - Generate every possible subarray.
    - Calculate the product of each subarray.
    - Keep track of the maximum product encountered.

    Approach:
    - Fix the starting index i.
    - Extend the subarray using index j.
    - Maintain a running product instead of recomputing
      the product for every subarray.
    - Update the answer whenever a larger product is found.

    Time Complexity: O(N^2)
    Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxiPro = nums[0];

        for(int i = 0; i < n; i++) {
            int product = 1;

            for(int j = i; j < n; j++) {
                product *= nums[j];
                maxiPro = max(maxiPro, product);
            }
        }

        return maxiPro;
    }
};


/*
    Problem: Maximum Product Subarray
    LeetCode: 152

    Intuition:
    - A negative number can turn a small product into a large one.
    - A zero breaks the product chain.
    - For any segment without zeros:
        * If negatives are even, the whole segment contributes.
        * If negatives are odd, remove either:
            - elements before the first negative, or
            - elements after the last negative.
    - A left-to-right (prefix) scan captures one possibility.
    - A right-to-left (suffix) scan captures the other.

    Approach:
    - Maintain prefix and suffix products.
    - Reset them to 1 whenever they become 0.
    - Update the answer using the maximum among:
        answer, prefix product, suffix product.
    - The maximum product subarray will be encountered
      in either the prefix or suffix traversal.

    Time Complexity: O(N)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        int maxiPro = INT_MIN;
        int pref = 1;
        int suff = 1;

        for(int i = 0; i < n; i++) {

            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;

            pref *= nums[i];
            suff *= nums[n - i - 1];

            maxiPro = max(maxiPro, max(pref, suff));
        }

        return maxiPro;
    }
};