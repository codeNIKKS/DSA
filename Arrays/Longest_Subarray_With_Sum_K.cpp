#include <bits/stdc++.h>
using namespace std;

/*
    LeetCode: Longest Subarray With Sum K
    File: Longest_Subarray_With_Given_Sum_K.cpp

    Brute Force Approach

    Intuition:
    Generate all possible subarrays using two loops.
    Maintain a running sum instead of recalculating
    subarray sum every time.

    Approach:
    1. Start subarray from every index i
    2. Extend subarray till index j
    3. Keep adding elements to running sum
    4. If sum becomes equal to k,
       update maximum length

    Time Complexity: O(n^2)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();
        int maxLen = 0;

        for(int i = 0; i < n; i++) {

            int sum = 0;

            for(int j = i; j < n; j++) {

                sum += nums[j];

                if(sum == k) {
                    maxLen = max(maxLen, j - i + 1);
                }
            }
        }

        return maxLen;
    }
};


/*
    LeetCode: Longest Subarray With Sum K
    File: Longest_Subarray_With_Given_Sum_K.cpp

    Better Approach (Prefix Sum + HashMap)

    Intuition:
    If:
        currentPrefixSum - previousPrefixSum = k

    then the elements between them form
    a subarray with sum k.

    We use a hashmap to store the first occurrence
    of every prefix sum for maximum subarray length.

    Approach:
    1. Maintain running prefix sum
    2. If sum == k, update answer
    3. Check if (sum - k) existed earlier
    4. If yes, calculate subarray length
    5. Store first occurrence of prefix sum only

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        int sum = 0;
        int maxLen = 0;

        for(int i = 0; i < nums.size(); i++) {

            // Calculate prefix sum
            sum += nums[i];

            // Case 1:
            // Subarray from index 0 to i has sum k
            if(sum == k) {
                maxLen = max(maxLen, i + 1);
            }

            // Remaining sum needed
            int rem = sum - k;

            // Check if rem existed earlier
            if(mp.find(rem) != mp.end()) {

                int len = i - mp[rem];

                maxLen = max(maxLen, len);
            }

            // Store first occurrence only
            if(mp.find(sum) == mp.end()) {
                mp[sum] = i;
            }
        }

        return maxLen;
    }
};


/*
    LeetCode: Longest Subarray With Sum K
    File: Longest_Subarray_With_Given_Sum_K.cpp

    Optimal Approach (Sliding Window)

    Intuition:
    This approach works only for positive/non-negative numbers.

    Since all elements are positive:
    - Expanding window increases sum
    - Shrinking window decreases sum

    This allows us to use two pointers efficiently.

    Approach:
    1. Expand the window using right pointer
    2. While sum > k, shrink window from left
    3. If sum == k, update maximum length
    4. Continue till right reaches end

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {

        int n = nums.size();

        int left = 0, right = 0;
        int sum = nums[0];

        int maxLen = 0;

        while(right < n) {

            // Shrink window if sum exceeds k
            while(left <= right && sum > k) {

                sum -= nums[left];
                left++;
            }

            // Update answer
            if(sum == k) {

                maxLen = max(maxLen, right - left + 1);
            }

            // Expand window
            right++;

            if(right < n) {

                sum += nums[right];
            }
        }

        return maxLen;
    }
};