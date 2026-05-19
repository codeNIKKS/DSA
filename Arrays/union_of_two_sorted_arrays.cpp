/*
========================================================
Leetcode Style Problem: Union of Two Sorted Arrays
Difficulty: Easy
Approach: Brute Force using Set
========================================================

Intuition:
- We need all distinct elements from both arrays in sorted order.
- A set in C++ automatically:
    1. Stores only unique elements
    2. Maintains elements in sorted order
- So we insert all elements from both arrays into a set
  and then copy them into the answer vector.

Approach:
1. Create a set<int>.
2. Insert all elements of nums1.
3. Insert all elements of nums2.
4. Traverse the set and store elements in answer vector.
5. Return the answer.

Time Complexity:
- O((n + m) log(n + m))

Space Complexity:
- O(n + m)

========================================================
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {

        set<int> st;
        vector<int> ans;

        // Insert elements from first array
        for(auto num : nums1) {
            st.insert(num);
        }

        // Insert elements from second array
        for(auto num : nums2) {
            st.insert(num);
        }

        // Store set elements into answer vector
        for(auto it : st) {
            ans.push_back(it);
        }

        return ans;
    }
};


/*
========================================================
Leetcode Style Problem: Union of Two Sorted Arrays
Difficulty: Easy
Approach: Better Approach using Map
========================================================

Intuition:
- We need all unique elements from both arrays in sorted order.
- map in C++ stores:
    1. Unique keys only
    2. Keys in sorted order
- So we can use a map to mark frequency of elements
  from both arrays and then collect all keys.

Approach:
1. Create a map<int, int>.
2. Traverse nums1 and store frequencies.
3. Traverse nums2 and store frequencies.
4. Traverse the map and push all keys into answer vector.
5. Return the answer.

Time Complexity:
- O((n + m) log(n + m))

Space Complexity:
- O(n + m)

========================================================
*/

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> mp;
        vector<int> ans;

        // Store elements of first array
        for(auto num : nums1) {
            mp[num]++;
        }

        // Store elements of second array
        for(auto num : nums2) {
            mp[num]++;
        }

        // Push unique sorted keys into answer vector
        for(auto &it : mp) {
            ans.push_back(it.first);
        }

        return ans;
    }
};


/*
========================================================
Leetcode Style Problem: Union of Two Sorted Arrays
Difficulty: Easy
Approach: Optimal using Two Pointers
========================================================

Intuition:
- Since both arrays are already sorted, we can use
  the merge technique of Merge Sort.
- We compare elements from both arrays using two pointers.
- Smaller element is added to the answer.
- To avoid duplicates, we only push an element if it
  is different from the last inserted element.

Approach:
1. Initialize two pointers i and j.
2. Compare nums1[i] and nums2[j].
3. Insert the smaller element if it is not duplicate.
4. Move the corresponding pointer.
5. After one array ends, insert remaining elements
   from the other array while avoiding duplicates.
6. Return the final union array.

Time Complexity:
- O(n + m)

Space Complexity:
- O(n + m)

========================================================
*/

class Solution {
public:
    vector<int> unionArray(vector<int>& nums1, vector<int>& nums2) {

        int n = nums1.size();
        int m = nums2.size();

        vector<int> ans;

        int i = 0;
        int j = 0;

        // Traverse both arrays
        while(i < n && j < m) {

            if(nums1[i] <= nums2[j]) {

                if(ans.empty() || ans.back() != nums1[i]) {
                    ans.push_back(nums1[i]);
                }

                i++;
            }
            else {

                if(ans.empty() || ans.back() != nums2[j]) {
                    ans.push_back(nums2[j]);
                }

                j++;
            }
        }

        // Insert remaining elements from nums1
        while(i < n) {

            if(ans.empty() || ans.back() != nums1[i]) {
                ans.push_back(nums1[i]);
            }

            i++;
        }

        // Insert remaining elements from nums2
        while(j < m) {

            if(ans.empty() || ans.back() != nums2[j]) {
                ans.push_back(nums2[j]);
            }

            j++;
        }

        return ans;
    }
};