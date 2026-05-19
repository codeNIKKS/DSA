#include <bits/stdc++.h>
using namespace std;


// PROBLEM:
//
// Count Elements With Maximum Frequency



// BRUTE FORCE APPROACH
//
// Traverse every element and count its frequency
// using another loop.
//
// Track the maximum frequency and add frequencies
// of elements having that maximum frequency.
//
// TC: O(n^2)
// SC: O(1)


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        int n = nums.size();

        int maxFreq = 0;
        int ans = 0;

        // Traverse every element
        for(int i = 0; i < n; i++) {

            int freq = 0;

            // Count frequency of nums[i]
            for(int j = i; j < n; j++) {

                if(nums[j] == nums[i]) {
                    freq++;
                }
            }

            // Update maximum frequency
            if(freq > maxFreq) {
                maxFreq = freq;
                ans = freq;
            }

            // Add frequencies having maximum frequency
            else if(freq == maxFreq) {
                ans += freq;
            }
        }

        return ans;
    }
};

// BETTER APPROACH
//
// Sort the array so equal elements become adjacent.
//
// Count frequency of each group using traversal.
//
// Track the maximum frequency and add frequencies
// of elements having that maximum frequency.
//
// TC: O(n log n)
// SC: O(1)


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();

        int maxFreq = 0;
        int ans = 0;

        int i = 0;

        while(i < n) {

            int j = i;

            // Count frequency of current element
            while(j < n && nums[j] == nums[i]) {
                j++;
            }

            int freq = j - i;

            // Update maximum frequency
            if(freq > maxFreq) {
                maxFreq = freq;
                ans = freq;
            }

            // Add frequencies having maximum frequency
            else if(freq == maxFreq) {
                ans += freq;
            }

            i = j;
        }

        return ans;
    }
};


// OPTIMAL APPROACH
//
// Use hashmap to store frequency of every element.
//
// Traverse the hashmap to find the maximum frequency
// and add frequencies of elements having that frequency.
//
// TC: O(n)
// SC: O(n)


class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        unordered_map<int,int> mp;

        // Store frequencies
        for(auto num : nums) {
            mp[num]++;
        }

        int maxFreq = 0;
        int ans = 0;

        // Traverse hashmap
        for(auto it : mp) {

            int freq = it.second;

            // Update maximum frequency
            if(freq > maxFreq) {
                maxFreq = freq;
                ans = freq;
            }

            // Add frequencies having maximum frequency
            else if(freq == maxFreq) {
                ans += freq;
            }
        }

        return ans;
    }
};