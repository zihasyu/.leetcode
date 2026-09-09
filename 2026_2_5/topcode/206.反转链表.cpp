/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 *
 * 1. 正插法（迭代while），最后返回pre
 * 2. 倒插法 （递归）
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
    ListNode *ans;
    ListNode *reverseList(ListNode *head)
    {
        // ListNode *pre = nullptr, *tmp = head;
        // while (tmp != nullptr)
        // {
        //     auto nxt = tmp->next;
        //     tmp->next = pre;
        //     pre = tmp;
        //     tmp = nxt;
        // }
        // return pre;
        if (head == nullptr || head->next == nullptr)
        {
            ans = head;
            return ans;
        }
        reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return ans;
    }
};
// @lc code=end
