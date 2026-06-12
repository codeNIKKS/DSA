/*
    Problem: Book Allocation Problem

    Given an array where nums[i] represents the number of pages in the i-th book
    and m students, allocate books such that:

    1. Each student gets at least one book.
    2. Each book is allocated to only one student.
    3. Allocation must be contiguous.
    4. Minimize the maximum pages assigned to a student.

    Intuition:
    ----------
    We need to minimize the maximum pages assigned to any student.

    Search Space:
    - Minimum possible answer = max(nums)
      (A student must take the book with maximum pages)

    - Maximum possible answer = sum(nums)
      (One student takes all books)

    We binary search on this answer space.

    For a candidate value 'mid':
    - Calculate how many students are required if no student
      can be assigned more than 'mid' pages.
    - If required students > m:
        mid is too small -> increase low
    - Else:
        allocation is possible -> try smaller answer

    Time Complexity: O(N * log(sum(nums)))
    Space Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:

    int students(vector<int>& books, int pages) {

        int cntStud = 1;
        int pageStud = 0;

        for (int i = 0; i < books.size(); i++) {

            if (pageStud + books[i] <= pages) {
                pageStud += books[i];
            }
            else {
                cntStud++;
                pageStud = books[i];
            }
        }

        return cntStud;
    }

    int findPages(vector<int>& nums, int m) {

        int n = nums.size();

        if (m > n) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        while (low <= high) {

            int mid = low + (high - low) / 2;

            int reqStudents = students(nums, mid);

            if (reqStudents > m) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;
    }
};