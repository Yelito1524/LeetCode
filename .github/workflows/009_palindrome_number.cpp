/*
 * ============================================================
 *  LeetCode #9 - Palindrome Number
 *  Difficulty : Easy
 *  Author     : Yael O. Melendez Rivera — B00643334
 * ============================================================
 *
 *  DESCRIPTION:
 *  Determine whether an integer is a palindrome without
 *  converting it to a string.
 *
 *  APPROACH:
 *  Reverse only the second half of the number and compare it
 *  to the first half. Negative numbers and multiples of 10
 *  (except 0) are immediately rejected. This avoids integer
 *  overflow since we only reverse half the digits.
 *
 *  Time  Complexity: O(log n)
 *  Space Complexity: O(1)
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        // Negatives and numbers ending in 0 (except 0 itself) can't be palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) return false;

        int reversed = 0;
        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        // Even length: x == reversed
        // Odd length: x == reversed / 10 (middle digit doesn't matter)
        return x == reversed || x == reversed / 10;
    }
};
