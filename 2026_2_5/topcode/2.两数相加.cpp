/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 * 用三目写确实很省空间
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0, nullptr);
        ListNode *ans = &dummy, *tmp = ans;
        int jinwei = 0, l1Val = 0, l2Val = 0;
        while (l1 || l2 || jinwei)
        {
            tmp->next = new ListNode(0, nullptr);
            tmp = tmp->next;
            l1Val = l1 ? l1->val : 0;
            l2Val = l2 ? l2->val : 0;
            tmp->val = (l1Val + l2Val + jinwei) % 10;
            jinwei = (l1Val + l2Val + jinwei) / 10 ? 1 : 0;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummy.next;
    }
};
// @lc code=end
