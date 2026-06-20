/*
    Problem: 451. Sort Characters By Frequency
    Link: https://leetcode.com/problems/sort-characters-by-frequency/

    Better Approach:
    1. Count frequency of each character using a hashmap.
    2. Store {character, frequency} pairs in a vector.
    3. Sort the vector in descending order of frequency.
    4. Append each character frequency number of times to the answer.

    Intuition:
    Instead of repeatedly finding the maximum frequency,
    sort all unique characters once according to their frequencies.
    Then build the answer from highest frequency to lowest.

    Time Complexity: O(n + k log k)
    Space Complexity: O(k)

    where:
    n = length of string
    k = number of unique characters

    Learning:
    - HashMap + Vector<Pair> + Custom Comparator is a common pattern.
    - Sorting unique characters is more efficient than repeatedly
      searching for the maximum frequency.
    - Custom comparator allows sorting by frequency instead of character.
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }

        vector<pair<char, int>> arr;

        for(auto it : freq) {
            arr.push_back(it);
        }

        sort(arr.begin(), arr.end(), cmp);

        string ans;

        for(auto it : arr) {
            ans.append(it.second, it.first);
        }

        return ans;
    }
};


/*
    Problem: 451. Sort Characters By Frequency
    Link: https://leetcode.com/problems/sort-characters-by-frequency/

    Optimal Approach (Max Heap / Priority Queue):
    1. Count frequency of each character using a hashmap.
    2. Store {frequency, character} in a max heap.
    3. Repeatedly extract the character with the highest frequency.
    4. Append the character frequency number of times to the answer.
    5. Continue until the heap becomes empty.

    Intuition:
    The problem repeatedly requires the character having the
    maximum frequency. A max heap is specifically designed for
    efficient retrieval of the largest element.

    Time Complexity: O(n + k log k)
    Space Complexity: O(k)

    where:
    n = length of string
    k = number of unique characters

    Learning:
    - Priority Queue is useful when repeatedly accessing the
      maximum/minimum element.
    - Storing {frequency, character} automatically prioritizes
      higher frequencies because pair comparison starts from
      the first element.
    - This pattern is frequently used in Top K Elements,
      Task Scheduler, Reorganize String, etc.
*/

class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for(char ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;

        for(auto it : freq) {
            pq.push({it.second, it.first});
        }

        string ans;

        while(!pq.empty()) {

            auto top = pq.top();
            pq.pop();

            ans.append(top.first, top.second);
        }

        return ans;
    }
};