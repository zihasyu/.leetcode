/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

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
        ListNode *p0 = &dummy, *tmp = p0->next;
        for (int i = 0; i < left - 1; i++)
        {
            if (tmp && tmp->next)
            {
                tmp = tmp->next;
                p0 = p0->next;
            }
        }
        auto pre = p0;
        for (int i = left; i <= right; i++)
        {
            if (tmp)
            {
                auto nxt = tmp->next;
                tmp->next = pre;
                pre = tmp;
                tmp = nxt;
            }
        }
        p0->next->next = tmp;
        p0->next = pre;

        return dummy.next;
    }
};
// @lc code=end
