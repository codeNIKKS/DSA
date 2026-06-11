/*
    Problem: 875. Koko Eating Bananas
    Link: https://leetcode.com/problems/koko-eating-bananas/

    Intuition:
    - We need to find the minimum eating speed k such that Koko
      can finish all banana piles within h hours.
    - If a speed k works, then every speed greater than k will
      also work.
    - This monotonic nature suggests Binary Search on Answers.

    Approach:
    - Search space:
        low  = 1
        high = maximum pile size
    - For a given speed k (mid), calculate the total hours needed:
        hours += ceil(pile / k)
    - Use integer ceiling:
        (pile + k - 1) / k
    - If hours <= h:
        speed works, try smaller speed.
    - Else:
        speed is too slow, increase speed.
    - At the end, low points to the minimum valid speed.

    Time Complexity:
    - O(n * log(maxPile))

    Space Complexity:
    - O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long calculateHours(vector<int>& piles, int speed) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + speed - 1LL) / speed;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = calculateHours(piles, mid);

            if (hours <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};