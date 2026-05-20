#include <bits/stdc++.h>
using namespace std;
/*
    LeetCode Problem: 268. Missing Number
    Topic: Arrays

    Brute Force Approach

    Intuition:
    Check every number from 0 to n and see whether it exists
    in the array or not. The first number that is not found
    is the missing number.

    Approach:
    - Traverse from 0 to n
    - For every number, scan the entire array
    - If the number is not present, return it

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i <= n; i++) {

            bool found = false;

            for(int j = 0; j < n; j++) {

                if(nums[j] == i) {
                    found = true;
                    break;
                }
            }

            if(!found) {
                return i;
            }
        }

        return -1;
    }
};

/*
    LeetCode Problem: 268. Missing Number
    Topic: Arrays

    Better Approach (Hashing)

    Intuition:
    Store the frequency/presence of every number from 0 to n
    using a hash array. The number whose frequency remains 0
    is the missing number.

    Approach:
    - Create a hash array of size n+1 initialized with 0
    - Mark every number present in nums
    - Traverse the hash array
    - The index having value 0 is the missing number

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        vector<int> freq(n + 1, 0);

        for(auto num : nums) {
            freq[num]++;
        }

        for(int i = 0; i <= n; i++) {

            if(freq[i] == 0) {
                return i;
            }
        }

        return -1;
    }
};

/*
    LeetCode Problem: 268. Missing Number
    Topic: Arrays

    Optimal Approach (Sum Formula)

    Intuition:
    The array contains numbers from 0 to n with one number missing.
    Find the expected sum of numbers from 0 to n and subtract
    the actual array sum to get the missing number.

    Approach:
    - Calculate the sum of all array elements
    - Calculate expected sum using formula:
      n * (n + 1) / 2
    - Return expectedSum - actualSum

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        int expectedSum = (n * (n + 1)) / 2;

        return expectedSum - sum;
    }
};

/*
    LeetCode Problem: 268. Missing Number
    Topic: Arrays

    Optimal Approach (XOR)

    Intuition:
    XOR of same numbers becomes 0.
    If we XOR all numbers from 0 to n and all elements
    of the array, all common elements cancel out and
    the remaining value is the missing number.

    Approach:
    - XOR all numbers from 1 to n
    - XOR all array elements
    - Return xor1 ^ xor2

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n = nums.size();

        int xor1 = 0;
        int xor2 = 0;

        for(int i = 0; i < n; i++) {

            xor1 ^= (i + 1);
            xor2 ^= nums[i];
        }

        return xor1 ^ xor2;
    }
};