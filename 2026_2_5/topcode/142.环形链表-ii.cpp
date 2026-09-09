/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 * 快慢指针+从头定理
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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return nullptr;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *Hit;
        int pos = -1;
        while (fast && fast->next)
        {
            slow = slow->next;       // 慢指针走一步
            fast = fast->next->next; // 快指针走两步
            if (slow == fast)
            {
                Hit = fast; // 相遇，说明有环
                pos = 0;
                break;
            }
        }
        if (pos == -1)
            return nullptr;
        else
        {
            ListNode *tmp = head;
            while (tmp != Hit)
            {
                tmp = tmp->next;
                Hit = Hit->next;
                // pos++;
            }
            return tmp;
        }
    }
};
// @lc code=end
