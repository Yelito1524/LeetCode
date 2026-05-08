/*
 * ============================================================
 *  LeetCode #2 - Add Two Numbers
 *  Difficulty : Medium
 *  Author     : Yael O. Melendez Rivera — B00643334
 * ============================================================
 *
 *  DESCRIPTION:
 *  Two non-empty linked lists represent two non-negative integers
 *  stored in reverse order. Add the two numbers and return the
 *  sum as a linked list (also in reverse order).
 *
 *  APPROACH:
 *  Traverse both lists simultaneously, summing digits and
 *  tracking the carry. A dummy head node simplifies building
 *  the result list. The loop continues until both lists are
 *  exhausted and there is no remaining carry.
 *
 *  Time  Complexity: O(max(m, n))
 *  Space Complexity: O(max(m, n))
 * ============================================================
 */

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = carry;

            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }

            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
        }

        return dummy.next;
    }
};
