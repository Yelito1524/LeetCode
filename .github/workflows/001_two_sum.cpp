/*
 * ============================================================
 *  LeetCode #1 - Two Sum
 *  Difficulty : Easy
 *  Author     : Yael O. Melendez Rivera — B00643334
 * ============================================================
 *
 *  DESCRIPTION:
 *  Given an array of integers and a target value, return the
 *  indices of the two numbers that add up to the target.
 *  Each input has exactly one solution; the same element
 *  cannot be used twice.
 *
 *  APPROACH:
 *  Use a hash map to store each value and its index as we
 *  iterate. For every element, check if its complement
 *  (target - current) already exists in the map. If so,
 *  we found our pair in a single pass.
 *
 *  Time  Complexity: O(n)
 *  Space Complexity: O(n)
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // value -> index

        for (int i = 0; i < (int)nums.size(); i++) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }

        return {};
    }
};
