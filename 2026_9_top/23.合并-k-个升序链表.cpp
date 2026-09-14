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
#include <bits/stdc++.h>
using namespace std;
// struct ListNode
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution
{
public:
    struct NewCompare
    {
        bool operator()(const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummy(0, nullptr);
        ListNode *tmp = &dummy;
        priority_queue<ListNode *, vector<ListNode *>, NewCompare> MinHeap;
        for (auto list : lists)
        {
            if (list)
                MinHeap.push(list);
        }
        while (!MinHeap.empty())
        {
            auto it = MinHeap.top();
            MinHeap.pop();
            tmp->next = it;
            tmp = tmp->next;
            if (it->next)
                MinHeap.push(it->next);
        }
        return dummy.next;
    }
};
// @lc code=end
