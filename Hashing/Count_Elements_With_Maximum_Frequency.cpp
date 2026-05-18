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