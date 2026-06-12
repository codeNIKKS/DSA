/*
    LeetCode 1482. Minimum Number of Days to Make m Bouquets

    Intuition:
    - We need the minimum day on which it is possible to make at least
      'm' bouquets, each containing exactly 'k' adjacent flowers.
    - If we can make 'm' bouquets on day X, then we can also make them
      on any day greater than X.
    - This monotonic property suggests Binary Search on the answer.

    Approach:
    1. Search in the range [min(bloomDay), max(bloomDay)].
    2. For a candidate day 'mid':
       - Count how many bouquets can be formed using flowers that have
         bloomed on or before 'mid'.
       - Traverse the array and maintain the count of consecutive bloomed flowers.
       - Whenever an unbloomed flower is encountered, add cnt/k bouquets
         and reset cnt.
       - After the loop, process the last segment as well.
    3. If bouquets >= m:
       - Try to find a smaller valid day.
    4. Otherwise:
       - Increase the day.

    Time Complexity: O(n * log(maxBloomDay - minBloomDay))
    Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countBouquets(vector<int>& bloomDay, int day, int k) {
        int bouquets = 0;
        int cnt = 0;

        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                bouquets += cnt / k;
                cnt = 0;
            }
        }

        bouquets += cnt / k;

        return bouquets;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if ((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int bouquets = countBouquets(bloomDay, mid, k);

            if (bouquets >= m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};