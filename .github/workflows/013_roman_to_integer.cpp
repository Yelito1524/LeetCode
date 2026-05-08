/*
 * ============================================================
 *  LeetCode #13 - Roman to Integer
 *  Difficulty : Easy
 *  Author     : Yael O. Melendez Rivera — B00643334
 * ============================================================
 *
 *  DESCRIPTION:
 *  Convert a Roman numeral string to an integer.
 *  Roman numerals use subtraction when a smaller value
 *  precedes a larger one (e.g., IV = 4, IX = 9).
 *
 *  APPROACH:
 *  Map each Roman symbol to its integer value. Iterate the
 *  string: if the current symbol is less than the next one,
 *  subtract it; otherwise, add it. This handles all
 *  subtractive cases in a single pass.
 *
 *  Time  Complexity: O(n)
 *  Space Complexity: O(1)
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;

        for (int i = 0; i < (int)s.size(); i++) {
            // If current value is less than next, subtract it
            if (i + 1 < (int)s.size() && val[s[i]] < val[s[i + 1]]) {
                result -= val[s[i]];
            } else {
                result += val[s[i]];
            }
        }

        return result;
    }
};
