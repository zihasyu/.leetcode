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
// class Solution
// {
// public:
//     struct CompareNodes
//     {
//         bool operator()(const ListNode *a, const ListNode *b)
//         {
//             return a->val > b->val;
//         }
//     };

//     priority_queue<ListNode *, std::vector<ListNode *>, CompareNodes> min_heap;

//     ListNode *mergeKLists(vector<ListNode *> &lists)
//     {
//         for (auto listNode : lists)
//         {
//             if (listNode)
//                 min_heap.push(listNode);
//         }
//         ListNode dummy(0);
//         ListNode *tail = &dummy;

//         while (!min_heap.empty())
//         {
//             // 2.1. 取出堆顶的最小节点
//             ListNode *min_node = min_heap.top();
//             min_heap.pop();

//             // 2.2. 将其连接到结果链表
//             tail->next = min_node;
//             tail = tail->next;

//             // 2.3. 如果该节点有后继，将其后继节点入堆
//             if (min_node->next)
//             {
//                 min_heap.push(min_node->next);
//             }
//         }
//         return dummy.next;
//     }
// };
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
        {
            return nullptr;
        }
        // 调用分治合并的辅助函数
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode *merge(vector<ListNode *> &lists, int left, int right)
    {
        if (left == right)
            return lists[left];
        if (left > right)
            return nullptr;

        auto mid = (left + right) / 2;

        ListNode *list1 = merge(lists, left, mid);
        ListNode *list2 = merge(lists, mid + 1, right);
        return mergeTwoLists(list1, list2);
    }
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;

        if (list1->val < list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }

}
// @lc code=end
