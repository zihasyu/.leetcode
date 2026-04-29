/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0, head);
        ListNode *p0 = &dummy;
        ListNode *tmp = head;
        int count = 0;
        while (tmp)
        {
            count++;
            tmp = tmp->next;
        }
        tmp = head;

        for (; count >= k; count -= k)
        {
            ListNode *pre = nullptr;
            for (int i = 0; i < k; i++)
            {
                auto nxt = tmp->next;
                tmp->next = pre;
                pre = tmp;
                tmp = nxt;
            }
            p0->next->next = tmp;
            auto nextP0 = p0->next;
            p0->next = pre;
            p0 = nextP0;
        }
        return dummy.next;
    }
};
// @lc code=end
