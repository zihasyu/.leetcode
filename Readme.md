# LeetCode 热题100 题目清单

## 1. 哈希 (Hash)
- LeetCode 1: 两数之和
- LeetCode 49: 字母异位词分组
- LeetCode 128: 最长连续序列

## 2. 双指针 (Two Pointers)
- LeetCode 15: 三数之和
- LeetCode 283: 移动零
- LeetCode 141: 环形链表
- LeetCode 11: 盛最多水的容器

## 3. 滑动窗口 (Sliding Window)
- LeetCode 3: 无重复字符的最长子串
- LeetCode 76: 最小覆盖子串
- LeetCode 438: 找到字符串中所有字母异位词
- LeetCode 239: 滑动窗口最大值

## 4. 子串 (Substring)
- LeetCode 560: 和为K的子数组
### LeetCode 53: 最大子数组和   
```c++
//kadane算法，记录以当前位置结尾的最大和
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int maxEndingHere = nums[0]; // 以当前位置结尾的最大和
        int maxSoFar = nums[0];      // 全局最大和
        for (int i = 1; i < nums.size(); i++)
        {
            maxEndingHere = max(nums[i], maxEndingHere + nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};
```
- LeetCode 209: 长度最小的子数组

## 5. 普通数组 (Array)
- LeetCode 41: 缺失的第一个正数
- LeetCode 442: 数组中重复的数据
- LeetCode 287: 寻找重复数
- LeetCode 56: 合并区间
- LeetCode 189: 轮转数组

## 6. 矩阵 (Matrix)
- LeetCode 54: 螺旋矩阵
- LeetCode 48: 旋转图像
- LeetCode 73: 矩阵置零
- LeetCode 240: 搜索二维矩阵II

## 7. 链表 (Linked List)
- LeetCode 206: 反转链表
- LeetCode 142: 环形链表 II
- LeetCode 21: 合并两个有序链表
- LeetCode 160: 相交链表
- LeetCode 234: 回文链表
- LeetCode 2: 两数相加
- LeetCode 19: 删除链表的倒数第 N 个节点
- LeetCode 24: 两两交换链表中的节点
- LeetCode 25: K 个一组翻转链表
- LeetCode 138: 复制带随机指针的链表
- LeetCode 148: 排序链表
- LeetCode 23: 合并K个升序链表
- LeetCode 146: LRU缓存机制

## 8. 二叉树 (Binary Tree)
- LeetCode 104: 二叉树的最大深度
- LeetCode 94: 二叉树的中序遍历
- LeetCode 226: 翻转二叉树
- LeetCode 101: 对称二叉树
- LeetCode 543: 二叉树的直径
- LeetCode 102: 二叉树的层序遍历
- LeetCode 108: 将有序数组转换为二叉搜索树
- LeetCode 98: 验证二叉搜索树
- LeetCode 230: 二叉搜索树中第K小的元素
- LeetCode 199: 二叉树的右视图
- LeetCode 114: 二叉树展开为链表
- LeetCode 105: 从前序与中序遍历序列构造二叉树
- LeetCode 437: 路径总和 III
- LeetCode 236: 二叉树的最近公共祖先
- LeetCode 124: 二叉树中的最大路径和

## 9. 图论 (Graph)
- LeetCode 200: 岛屿数量
- LeetCode 207: 课程表
- LeetCode 133: 克隆图
- LeetCode 994: 腐烂的橘子
- LeetCode 208: 实现 Trie (前缀树)

## 10. 回溯 (Backtracking)
- LeetCode 46: 全排列
- LeetCode 78: 子集
- LeetCode 17: 电话号码的字母组合
- LeetCode 22: 括号生成
- LeetCode 79: 单词搜索
- LeetCode 131: 分割回文串
- LeetCode 51: N皇后

## 11. 二分查找 (Binary Search)
- LeetCode 153: 寻找旋转排序数组中的最小值
- LeetCode 34: 在排序数组中查找元素的第一个和最后一个位置
- LeetCode 74: 搜索二维矩阵
- LeetCode 35: 搜索插入位置
- LeetCode 33: 搜索旋转排序数组

## 12. 栈 (Stack)
- LeetCode 20: 有效的括号
- LeetCode 155: 最小栈
- LeetCode 394: 字符串解码
- LeetCode 739: 每日温度

## 13. 堆 (Heap)
- LeetCode 215: 数组中的第K个最大元素
- LeetCode 347: 前K个高频元素
- LeetCode 295: 数据流的中位数

## 14. 贪心算法 (Greedy)
- LeetCode 121: 买卖股票的最佳时机
- LeetCode 55: 跳跃游戏
- LeetCode 45: 跳跃游戏 II
- LeetCode 763: 划分字母区间

## 15. 动态规划 (DP)
- LeetCode 70: 爬楼梯
- LeetCode 118: 杨辉三角
- LeetCode 198: 打家劫舍
- LeetCode 279: 完全平方数
- LeetCode 322: 零钱兑换
- LeetCode 139: 单词拆分
- LeetCode 300: 最长递增子序列
- LeetCode 152: 乘积最大子数组
- LeetCode 416: 分割等和子集
- LeetCode 32: 最长有效括号

## 16. 高级动态规划
- LeetCode 62: 不同路径
- LeetCode 64: 最小路径和
- LeetCode 5: 最长回文子串
- LeetCode 1143: 最长公共子序列
- LeetCode 72: 编辑距离

## 17. 技巧 (Tricks)
- LeetCode 136: 只出现一次的数字
- LeetCode 169: 多数元素
- LeetCode 75: 颜色分类
- LeetCode 31: 下一个排列

## 18. 字符串算法 (String)
- LeetCode 28: 实现strStr()
- LeetCode 14: 最长公共前缀

## 19. 并查集 (Union Find)
- LeetCode 547: 省份数量
- LeetCode 684: 冗余连接