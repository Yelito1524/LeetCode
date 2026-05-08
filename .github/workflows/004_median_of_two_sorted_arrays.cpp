/*
 * ============================================================
 *  LeetCode #4 - Median of Two Sorted Arrays
 *  Difficulty : Hard
 *  Author     : Yael O. Melendez Rivera — B00643334
 * ============================================================
 *
 *  DESCRIPTION:
 *  Given two sorted arrays nums1 and nums2 of size m and n,
 *  return the median of the two sorted arrays combined.
 *  The solution must run in O(log(min(m, n))) time.
 *
 *  APPROACH:
 *  Binary search on the smaller array to find a partition point
 *  such that the left halves of both arrays together contain
 *  exactly half of all elements. The median is then derived
 *  from the boundary values of the two partitions.
 *
 *  Time  Complexity: O(log(min(m, n)))
 *  Space Complexity: O(1)
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Always binary search on the smaller array
        if (nums1.size() > nums2.size()) swap(nums1, nums2);

        int m = nums1.size(), n = nums2.size();
        int lo = 0, hi = m;
        int half = (m + n + 1) / 2;

        while (lo <= hi) {
            int i = (lo + hi) / 2; // partition index for nums1
            int j = half - i;      // partition index for nums2

            int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int r1 = (i == m) ? INT_MAX : nums1[i];
            int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int r2 = (j == n) ? INT_MAX : nums2[j];

            if (l1 <= r2 && l2 <= r1) {
                // Perfect partition found
                if ((m + n) % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else if (l1 > r2) hi = i - 1; // too far right on nums1
            else              lo = i + 1; // too far left on nums1
        }

        return 0.0;
    }
};
