/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    // ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    // {
    //     ListNode dummy(0, nullptr);
    //     ListNode *tmp = &dummy;
    //     while (list1 && list2)
    //     {
    //         if (list1->val > list2->val)
    //         {
    //             tmp->next = list2;
    //             tmp = tmp->next;
    //             list2 = list2->next;
    //         }
    //         else
    //         {
    //             tmp->next = list1;
    //             tmp = tmp->next;
    //             list1 = list1->next;
    //         }
    //     }
    //     tmp->next = list1 == nullptr ? list2 : list1;
    //     return dummy.next;
    // }
    // ListNode *mergeKLists(vector<ListNode *> &lists)
    // {
    //     if (lists.empty())
    //         return nullptr;
    //     return mergeRange(lists, 0, lists.size() - 1);
    // }
    // ListNode *mergeRange(vector<ListNode *> &lists, int left, int right)
    // {
    //     if (left == right)
    //         return lists[left];
    //     int mid = left + (right - left) / 2;
    //     ListNode *l = mergeRange(lists, left, mid);
    //     ListNode *r = mergeRange(lists, mid + 1, right);
    //     return mergeTwoLists(l, r); // 归并写法
    // }
    // 最小堆写法
    struct CompareNode
    {
        bool operator()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };
    priority_queue<ListNode *, vector<ListNode *>, CompareNode> MinHeap;

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        for (auto list : lists)
        {
            if (list)
                MinHeap.push(list);
        }
        ListNode dummy(0, nullptr);
        ListNode *tmp = &dummy;
        while (!MinHeap.empty())
        {
            auto tmpNode = MinHeap.top();
            tmp->next = tmpNode;
            tmp = tmp->next;
            MinHeap.pop();
            if (tmpNode->next)
                MinHeap.push(tmpNode->next);
        }

        return dummy.next;
    }
};
// @lc code=end
