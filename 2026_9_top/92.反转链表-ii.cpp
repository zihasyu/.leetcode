/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */
#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode dummy(0, head);
        auto preLeft = &dummy;
        for (int i = 1; i < left; i++)
        {
            preLeft = preLeft->next;
        }
        ListNode *pre = nullptr, *tmp = preLeft->next;
        for (int i = left; i <= right; i++)
        {
            ListNode *nxt = tmp->next;
            tmp->next = pre;
            pre = tmp;
            tmp = nxt;
        }
        preLeft->next->next = tmp;
        preLeft->next = pre;
        return dummy.next;
    }
};
// @lc code=end
