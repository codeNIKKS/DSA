/*
========================================
Leetcode 560. Subarray Sum Equals K
========================================

Problem:
Given an integer array nums and an integer k,
return the total number of continuous subarrays
whose sum equals k.

----------------------------------------
Brute Force Approach
----------------------------------------

Intuition:
Generate all possible subarrays using two loops.
Maintain a running sum for every starting index.

If the running sum becomes equal to k,
increase the count.

----------------------------------------
Approach:
1. Start subarray from every index i
2. Maintain sum = 0
3. Extend subarray using j
4. Add nums[j] to sum
5. If sum == k, increment count

----------------------------------------
Time Complexity:
O(n^2)

Space Complexity:
O(1)

----------------------------------------
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        int count = 0;

        for(int i = 0; i < n; i++) {

            int sum = 0;

            for(int j = i; j < n; j++) {

                sum += nums[j];

                if(sum == k) {
                    count++;
                }
            }
        }

        return count;
    }
};


/*
========================================
Leetcode 560. Subarray Sum Equals K
========================================

Problem:
Given an integer array nums and an integer k,
return the total number of continuous subarrays
whose sum equals k.

----------------------------------------
Optimal Approach (Prefix Sum + HashMap)
----------------------------------------

Intuition:
If:

currentPrefixSum - previousPrefixSum = k

Then:

previousPrefixSum = currentPrefixSum - k

So for every index, we check whether
(sum - k) already existed earlier.

If it existed, then a subarray with sum k exists.

We store:
prefixSum -> frequency

----------------------------------------
Approach:
1. Use a hashmap to store prefix sum frequencies
2. Initialize mp[0] = 1
3. Traverse array and maintain running sum
4. Check if (sum - k) exists in map
5. Add its frequency to count
6. Store current prefix sum frequency

----------------------------------------
Time Complexity:
O(n)

Space Complexity:
O(n)

----------------------------------------
*/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if(mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            mp[sum]++;
        }

        return count;
    }
};