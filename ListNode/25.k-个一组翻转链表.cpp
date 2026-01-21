/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */
#include <bits/stdc++.h>
using namespace std;
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
    bool IsEnough(ListNode *tmp, int k)
    {
        while (k--)
        {
            if (tmp == nullptr)
                return false;
            tmp = tmp->next;
        }
        return true;
    }

    void reverseK(ListNode *start, int k)
    {
        ListNode *prev = start->next; // 反转后的尾节点
        ListNode *cur = prev->next;

        // 反转 k-1 次(第一个节点不动,后面 k-1 个节点依次前移)
        for (int i = 0; i < k - 1; i++)
        {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        // 连接反转后的链表
        ListNode *tail = start->next; // 原来的头变成尾
        tail->next = cur;             // 尾节点连接后续部分
        start->next = prev;           // 前驱连接新头
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode Head(0);
        Head.next = head;
        ListNode *tmpNode = &Head;

        while (IsEnough(tmpNode->next, k))
        {
            reverseK(tmpNode, k);
            tmpNode = tmpNode->next;
            for (int i = 1; i < k; i++)
                tmpNode = tmpNode->next;
        }
        return Head.next;
    }
};
// @lc code=end
