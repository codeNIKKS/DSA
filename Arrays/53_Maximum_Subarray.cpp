#include <bits/stdc++.h>
using namespace std;
/*
    LeetCode 53. Maximum Subarray
    Brute Force Approach

    Intuition:
    - Generate all possible subarrays.
    - Calculate sum of each subarray.
    - Store the maximum sum obtained.

    Approach:
    - Fix starting index i.
    - Extend subarray till j.
    - Continuously add elements to avoid recalculating sum.

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int n = nums.size();
        int maxsum = INT_MIN;

        for(int i = 0; i < n; i++) {

            int sum = 0;

            for(int j = i; j < n; j++) {

                sum += nums[j];

                maxsum = max(maxsum, sum);
            }
        }

        return maxsum;
    }
};


/*
    LeetCode 53. Maximum Subarray
    Better Approach (Prefix Sum + Minimum Prefix Sum)

    Intuition:
    - Any subarray sum can be written as:
        currentPrefixSum - previousPrefixSum

    - To maximize the subarray sum ending at current index,
      we should subtract the minimum prefix sum seen so far.

    - Instead of storing all previous prefix sums in a map,
      only the minimum prefix sum is required.

    Approach:
    - Maintain:
        1. current prefix sum
        2. minimum prefix sum seen so far
        3. maximum subarray sum

    - At every index:
        maxSubarray = currentPrefix - minPrefix

    Learning:
    - Initially tried storing all prefix sums using map.
    - Realized only the smallest previous prefix sum matters.
    - This reduces O(n log n) map approach to O(n).

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int mini = 0;
        int maxsum = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            maxsum = max(maxsum, sum - mini);

            mini = min(mini, sum);
        }

        return maxsum;
    }
};


/*
    LeetCode 53. Maximum Subarray
    Optimal Approach (Kadane's Algorithm)

    Intuition:
    - A negative running sum can never help in maximizing
      a future subarray sum.

    - If current sum becomes negative,
      discard it and start a new subarray.

    Why?
    - Suppose currentSum < 0

      Then for any future element x:

            currentSum + x < x

      So carrying a negative sum only decreases future sums.

    Approach:
    - Maintain a running sum.
    - Update maximum answer at every step.
    - Reset running sum to 0 whenever it becomes negative.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxsum = INT_MIN;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            maxsum = max(maxsum, sum);

            if(sum < 0) {
                sum = 0;
            }
        }

        return maxsum;
    }
};

/*
    LeetCode 53. Maximum Subarray
    Printing the Maximum Sum Subarray (Kadane's Algorithm)

    Intuition:
    - Negative running sum cannot help future subarrays.
    - Whenever running sum becomes negative,
      start a new subarray from next index.

    Additional Tracking:
    - start     -> temporary starting index
    - ansStart  -> starting index of final answer
    - ansEnd    -> ending index of final answer

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int sum = 0;
        int maxsum = INT_MIN;

        int start = 0;
        int ansStart = -1;
        int ansEnd = -1;

        for(int i = 0; i < nums.size(); i++) {

            sum += nums[i];

            if(sum > maxsum) {

                maxsum = sum;

                ansStart = start;
                ansEnd = i;
            }

            if(sum < 0) {

                sum = 0;

                start = i + 1;
            }
        }

        // Printing the subarray
        for(int i = ansStart; i <= ansEnd; i++) {

            cout << nums[i] << " ";
        }

        cout << endl;

        return maxsum;
    }
};