/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * 最直接的思路的迭代，但其实递归更简洁
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0, nullptr);
        ListNode *tmp = &dummy;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                tmp->next = list1;
                list1 = list1->next;
            }
            else
            {
                tmp->next = list2;
                list2 = list2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = list1 ? list1 : list2;
        return dummy.next;
    }
};

// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         // 基本情况：如果一个链表为空，返回另一个
//         if (!list1) return list2;
//         if (!list2) return list1;

//         // 递归步骤
//         if (list1->val < list2->val)
//         {
//             // list1 的头更小，所以它作为新头
//             // 它的 next 指向 list1->next 和 list2 的合并结果
//             list1->next = mergeTwoLists(list1->next, list2);
//             return list1;
//         }
//         else
//         {
//             // list2 的头更小或相等
//             list2->next = mergeTwoLists(list1, list2->next);
//             return list2;
//         }
//     }
// };
// @lc code=end
