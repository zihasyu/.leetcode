/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode *fast = head->next, *slow = head;
        while (fast && fast->next)
        {
            if (fast == slow)
                return true;
            slow = slow->next;
            fast = fast->next->next;
        }

        return false;
    }
};
// @lc code=end
