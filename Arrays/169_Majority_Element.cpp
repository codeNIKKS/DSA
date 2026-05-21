#include <bits/stdc++.h>
using namespace std;
/*
    LeetCode Problem: 169. Majority Element
    Difficulty: Easy

    Approach: Brute Force

    Intuition:
    For every element in the array, count how many times it appears.
    If its frequency becomes greater than n/2, then that element
    is the majority element.

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int count = 0;

            for(int j = 0; j < n; j++) {

                if(nums[j] == nums[i]) {
                    count++;
                }
            }

            if(count > n / 2) {
                return nums[i];
            }
        }

        return -1;
    }
};


/*
    LeetCode Problem: 169. Majority Element
    Difficulty: Easy

    Approach: Better Approach using Hashing

    Intuition:
    Store the frequency of every element using an unordered_map.
    Traverse the map and return the element whose frequency
    is greater than n/2.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int, int> mp;

        for(auto num : nums) {
            mp[num]++;
        }

        for(auto it : mp) {

            if(it.second > n / 2) {
                return it.first;
            }
        }

        return -1;
    }
};


/*
    LeetCode Problem: 169. Majority Element
    Difficulty: Easy

    Approach: Optimal Approach (Moore's Voting Algorithm)

    Intuition:
    The majority element appears more than n/2 times.
    We maintain a candidate element and a count.

    - If count becomes 0, choose the current element as candidate.
    - If the current element matches the candidate, increment count.
    - Otherwise, decrement count.

    Since the majority element appears more than half the time,
    it will always remain as the final candidate.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {

        int count = 0;
        int el;

        for(int i = 0; i < nums.size(); i++) {

            if(count == 0) {
                el = nums[i];
                count = 1;
            }

            else if(nums[i] == el) {
                count++;
            }

            else {
                count--;
            }
        }

        return el;
    }
};