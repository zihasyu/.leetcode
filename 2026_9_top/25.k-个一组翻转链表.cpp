/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0, head);
        int n = 0;
        auto counter = head;
        while (counter)
        {
            counter = counter->next;
            n++;
        }
        ListNode *preLeft = &dummy, *tmp = head;
        for (int i = n; i >= k; i -= k)
        {
            ListNode *pre = nullptr;
            for (int j = 0; j < k; j++)
            {
                auto nxt = tmp->next;
                tmp->next = pre;
                pre = tmp;
                tmp = nxt;
            }
            preLeft->next->next = tmp;
            auto nxtPreLeft = preLeft->next;
            preLeft->next = pre;
            preLeft = nxtPreLeft;
        }
        return dummy.next;
    }
};
// @lc code=end
