/*
    LeetCode 15. 3Sum

    Brute Force Approach

    Intuition:
    - Generate every possible triplet using three nested loops.
    - Check whether the sum of the triplet is equal to 0.
    - To avoid duplicate triplets:
        1. Sort the original array once.
        2. Since i < j < k, every generated triplet is automatically sorted.
        3. Store triplets in a set to keep only unique triplets.
    - Convert the set into the required vector<vector<int>> answer.

    Approach:
    1. Sort the array.
    2. Use three loops to generate all possible triplets.
    3. If nums[i] + nums[j] + nums[k] == 0:
         - Insert the triplet into a set.
    4. Convert the set into a vector and return it.

    Time Complexity:
    - Sorting: O(N log N)
    - Three nested loops: O(N^3)
    - Overall: O(N^3)

    Space Complexity:
    - O(M)
      where M = number of unique triplets stored in the set.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        set<vector<int>> st;

        for(int i = 0; i < n; i++) {

            for(int j = i + 1; j < n; j++) {

                for(int k = j + 1; k < n; k++) {

                    if(nums[i] + nums[j] + nums[k] == 0) {

                        st.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(), st.end());

        return ans;
    }
};


/*
    LeetCode 15. 3Sum

    Better Approach (Hashing)

    Intuition:
    - Fix the first element nums[i].
    - For every nums[j] after i, calculate the third element required
      to make the sum equal to 0.

            nums[i] + nums[j] + third = 0
            third = -(nums[i] + nums[j])

    - Use a hashset to quickly check whether the required third
      element has already appeared.
    - Whenever a valid triplet is found:
        1. Create the triplet.
        2. Sort the triplet.
        3. Store it in a set to avoid duplicates.
    - Finally convert the set into the required answer format.

    Approach:
    1. Iterate over each index i.
    2. Create a fresh hashset for every i.
    3. For each j > i:
         - Calculate third = -(nums[i] + nums[j]).
         - If third exists in hashset:
               -> valid triplet found.
         - Insert nums[j] into hashset.
    4. Store unique triplets in a set.
    5. Convert set to vector and return.

    Time Complexity:
    - Outer Loop: O(N)
    - Inner Loop: O(N)
    - Hash Lookup: O(1) average

    Overall: O(N² log M)

    where M = number of unique triplets stored in the set.

    Space Complexity:
    - O(N) for hashset
    - O(M) for storing unique triplets

    Overall: O(N + M)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        set<vector<int>> st;

        for(int i = 0; i < n; i++) {

            unordered_set<int> hashset;

            for(int j = i + 1; j < n; j++) {

                int third = -(nums[i] + nums[j]);

                if(hashset.find(third) != hashset.end()) {

                    vector<int> temp = {nums[i], nums[j], third};

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                hashset.insert(nums[j]);
            }
        }

        return vector<vector<int>>(st.begin(), st.end());
    }
};


/*
    LeetCode 15. 3Sum

    Optimal Approach (Sorting + Two Pointers)

    Intuition:
    - Sort the array first.
    - Fix one element nums[i].
    - Now the problem becomes finding two numbers whose sum equals
      -nums[i].
    - Use two pointers:
        j = i + 1  (left pointer)
        k = n - 1  (right pointer)

    - If current sum is smaller than 0:
          move j forward to increase the sum.
    - If current sum is greater than 0:
          move k backward to decrease the sum.
    - If sum becomes 0:
          store the triplet and skip duplicates.

    Why skip duplicates?
    - The answer must contain only unique triplets.
    - Skip duplicate values of i.
    - After finding a valid triplet, skip duplicate values of j and k.

    Approach:
    1. Sort the array.
    2. Iterate through each index i.
    3. Skip duplicate values of i.
    4. Use two pointers j and k.
    5. Depending on the sum:
         - sum < 0  -> j++
         - sum > 0  -> k--
         - sum == 0 -> store triplet and skip duplicates
    6. Return the answer.

    Time Complexity:
    - Sorting: O(N log N)
    - Outer Loop: O(N)
    - Two Pointers: O(N)

    Overall: O(N²)

    Space Complexity:
    - O(1) auxiliary space
    - Ignoring the output array.
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++) {

            if(i > 0 && nums[i] == nums[i - 1]) continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {

                int sum = nums[i] + nums[j] + nums[k];

                if(sum < 0) {
                    j++;
                }
                else if(sum > 0) {
                    k--;
                }
                else {

                    ans.push_back({nums[i], nums[j], nums[k]});

                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j - 1]) j++;
                    while(j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }

        return ans;
    }
};