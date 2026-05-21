#include <bits/stdc++.h>
using namespace std;
/*
============================================================================
1. Two Sum
Leetcode: 1
Topic: Arrays, Hashing
Difficulty: Easy
============================================================================

Problem:
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input has exactly one solution,
and you may not use the same element twice.

----------------------------------------------------------------------------

Brute Force Approach:
- Check every possible pair using two nested loops.
- If the sum of a pair equals target, return their indices.

----------------------------------------------------------------------------

Time Complexity: O(n^2)
Space Complexity: O(1)

============================================================================
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                if(nums[i] + nums[j] == target) {

                    return {i, j};
                }
            }
        }

        return {};
    }
};


/*
============================================================================
1. Two Sum
Leetcode: 1
Topic: Arrays, Hashing
Difficulty: Easy
============================================================================

Problem:
Given an array of integers nums and an integer target,
return indices of the two numbers such that they add up to target.

You may assume that each input has exactly one solution,
and you may not use the same element twice.

----------------------------------------------------------------------------

Optimal Approach (Hashing):
- Use an unordered_map to store:
      number -> index

- For every element:
    rem = target - nums[i]

- Check if rem already exists in the map.
- If yes, we found the required pair.
- Otherwise, store current element in the map.

----------------------------------------------------------------------------

Time Complexity: O(n)
Space Complexity: O(n)

============================================================================
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int, int> mp;

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int rem = target - nums[i];

            if(mp.find(rem) != mp.end()) {

                return {mp[rem], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};