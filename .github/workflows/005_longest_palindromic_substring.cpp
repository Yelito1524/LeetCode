/*
 * ============================================================
 *  LeetCode #5 - Longest Palindromic Substring
 *  Difficulty : Medium
 *  Author     : Yael O. Melendez Rivera — B00643334
 * ============================================================
 *
 *  DESCRIPTION:
 *  Given a string s, return the longest palindromic substring.
 *  A palindrome reads the same forwards and backwards.
 *
 *  APPROACH:
 *  Expand Around Center — for each character (and each pair of
 *  adjacent characters), expand outward as long as the characters
 *  on both sides match. Covers both odd-length ("aba") and
 *  even-length ("bb") palindromes.
 *
 *  Time  Complexity: O(n²)
 *  Space Complexity: O(1)
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;

        auto expand = [&](int left, int right) {
            while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
                if (right - left + 1 > maxLen) {
                    maxLen = right - left + 1;
                    start = left;
                }
                left--;
                right++;
            }
        };

        for (int i = 0; i < (int)s.size(); i++) {
            expand(i, i);     // Odd length:  "aba"
            expand(i, i + 1); // Even length: "bb"
        }

        return s.substr(start, maxLen);
    }
};
