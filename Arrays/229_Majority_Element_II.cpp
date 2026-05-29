/*
    LeetCode 229. Majority Element II

    Brute Force Approach

    Intuition:
    - For every element, count its frequency in the entire array.
    - If its frequency is greater than n/3, add it to the answer.
    - Avoid processing an element multiple times by checking whether
      it is already present in the answer vector.
    - Since an array can have at most 2 majority elements (> n/3),
      we can stop once the answer size becomes 2.

    Approach:
    1. Traverse each element of the array.
    2. Skip the element if it is already present in the answer.
    3. Count its frequency by scanning the entire array.
    4. If frequency > n/3, add it to the answer.
    5. If answer size reaches 2, break.

    Time Complexity: O(n²)
    Space Complexity: O(1) (excluding output array)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {

            // Skip if already added to answer
            if (find(ans.begin(), ans.end(), nums[i]) != ans.end()) {
                continue;
            }

            int cnt = 0;

            // Count frequency of nums[i]
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    cnt++;
                }
            }

            // Check if frequency is greater than n/3
            if (cnt > n / 3) {
                ans.push_back(nums[i]);
            }

            // At most 2 majority elements are possible
            if (ans.size() == 2) {
                break;
            }
        }

        return ans;
    }
};


/*
    LeetCode 229. Majority Element II

    Better Approach (Hash Map)

    Intuition:
    - Store the frequency of each element using a hash map.
    - As soon as an element's frequency becomes greater than n/3,
      add it to the answer.
    - We use frequency == (n/3 + 1) to ensure that each majority
      element is added only once.
    - Since there can be at most 2 majority elements, we can stop
      once the answer size becomes 2.

    Approach:
    1. Create a hash map to store frequencies.
    2. Traverse the array and update frequency of each element.
    3. If frequency becomes exactly (n/3 + 1), add the element
       to the answer.
    4. If answer size reaches 2, break.
    5. Return the answer.

    Time Complexity: O(n)
    Space Complexity: O(n)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        vector<int> ans;

        for (int num : nums) {
            mp[num]++;

            // Add only once when crossing the threshold
            if (mp[num] == (n / 3) + 1) {
                ans.push_back(num);
            }

            // At most 2 majority elements are possible
            if (ans.size() == 2) {
                break;
            }
        }

        return ans;
    }
};


/*
    LeetCode 229. Majority Element II

    Optimal Approach (Boyer-Moore Voting Algorithm)

    Intuition:
    - An element appearing more than n/3 times can have at most
      2 such candidates in the array.
    - Use two candidates and two counters to find the potential
      majority elements.
    - First pass finds the candidates.
    - Second pass verifies whether their actual frequencies are
      greater than n/3.

    Approach:
    1. Maintain two candidates (element1, element2) and their counts.
    2. Traverse the array:
       - If current element matches a candidate, increment its count.
       - If a count becomes 0, assign the current element as candidate.
       - Otherwise decrement both counts.
    3. After the first pass, we get at most two potential candidates.
    4. Count their actual frequencies in a second pass.
    5. Add candidates whose frequency is greater than n/3.

    Time Complexity: O(n)
    Space Complexity: O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();

        int element1 = 0, element2 = 0;
        int cnt1 = 0, cnt2 = 0;

        // Step 1: Find potential candidates
        for (int num : nums) {

            if (cnt1 == 0 && num != element2) {
                element1 = num;
                cnt1 = 1;
            }
            else if (cnt2 == 0 && num != element1) {
                element2 = num;
                cnt2 = 1;
            }
            else if (num == element1) {
                cnt1++;
            }
            else if (num == element2) {
                cnt2++;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // Step 2: Verify the candidates
        cnt1 = 0;
        cnt2 = 0;

        for (int num : nums) {
            if (num == element1) {
                cnt1++;
            }
            else if (num == element2) {
                cnt2++;
            }
        }

        vector<int> ans;

        if (cnt1 > n / 3) {
            ans.push_back(element1);
        }

        if (cnt2 > n / 3) {
            ans.push_back(element2);
        }

        return ans;
    }
};