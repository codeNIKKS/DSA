#include <bits/stdc++.h>
using namespace std;
/*
===========================================================
Leetcode 136. Single Number
===========================================================

Problem:
Given a non-empty array of integers nums, every element
appears twice except for one. Find that single one.

-----------------------------------------------------------
Brute Force Approach
-----------------------------------------------------------

Intuition:
For every element, count how many times it appears in
the array using another loop.

If the count becomes 1, that element is the answer.

Approach:
1. Traverse every element using outer loop.
2. For each element, count its frequency using inner loop.
3. If frequency is 1, return that element.

Time Complexity: O(n^2)
Space Complexity: O(1)

===========================================================
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {

                if(nums[i] == nums[j]) {
                    count++;
                }
            }

            if(count == 1) {
                return nums[i];
            }
        }

        return -1;
    }
};

/*
===========================================================
Leetcode 136. Single Number
===========================================================

Problem:
Given a non-empty array of integers nums, every element
appears twice except for one. Find that single one.

-----------------------------------------------------------
Better Approach (Hashing)
-----------------------------------------------------------

Intuition:
Store the frequency of every element using a hashmap.

The element whose frequency becomes 1 is the required
single number.

Approach:
1. Create an unordered_map to store frequencies.
2. Traverse the array and update frequency count.
3. Traverse the hashmap.
4. Return the element whose frequency is 1.

Time Complexity: O(n)
Space Complexity: O(n)

===========================================================
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        unordered_map<int, int> freq;

        for(auto num : nums) {
            freq[num]++;
        }

        for(auto it : freq) {

            if(it.second == 1) {
                return it.first;
            }
        }

        return -1;
    }
};


/*
===========================================================
Leetcode 136. Single Number
===========================================================

Problem:
Given a non-empty array of integers nums, every element
appears twice except for one. Find that single one.

-----------------------------------------------------------
Optimal Approach (Bit Manipulation - XOR)
-----------------------------------------------------------

Intuition:
XOR of two same numbers is always 0.

Properties of XOR:
1. a ^ a = 0
2. 0 ^ a = a

So, when we XOR all elements together:
- Duplicate elements cancel each other.
- Only the single element remains.

Approach:
1. Initialize a variable xorr = 0.
2. Traverse the array.
3. XOR every element with xorr.
4. Return xorr.

Time Complexity: O(n)
Space Complexity: O(1)

===========================================================
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int xorr = 0;

        for(int i = 0; i < nums.size(); i++) {
            xorr ^= nums[i];
        }

        return xorr;
    }
};