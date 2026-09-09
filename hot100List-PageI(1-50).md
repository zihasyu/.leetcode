## 哈希
### √1.两数之和（纯map）

```c++
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> Map;
        int index=0;
        for(auto num:nums){
            if(Map.find(target-num)!=Map.end()){
                return {Map[target-num],index};
            }
            else{
                Map[num]=index++;
            }
        }
        return {};
    }
};
```
### √49.字母异位词分组（sort+map）
词内排序后一致
`auto it:Map`是个正常变量，不是指针。
```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> Map;
        for(auto s : strs){
            string tmp=s;
            ranges::sort(tmp);
            Map[tmp].push_back(s);
        }
        vector<vector<string>> ans;
        for(auto it:Map){
            ans.push_back(it.second);
        }
        return ans;
    }
};
```

### 128.最长连续序列 vector转set
```c++
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        if(nums.size()<=1)
            return nums.size();
        int ans=0,pre_num=INT_MAX,tmp=1;
        for(auto x: st){
            if(pre_num==x-1){
                tmp++;
                ans=max(ans,tmp);
                pre_num=x;
            }else{
                pre_num=x;
                tmp=1;
                ans=max(ans,tmp);
            }
        }
        return ans;
    }
};
```

## 双指针

### √283.移动零 本格双指针（快慢）
```c++
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int temp=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                nums[temp]=nums[i];
                temp++;
            }
        }
        while(temp<n){
            nums[temp++]=0;
        }

    }
};
```

### 15.三数之和 两次去重逻辑

```c++
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i++){
            if(i && nums[i]==nums[i-1])
                continue;
            auto target=-1*nums[i];
            int left=i+1,right=nums.size()-1;
            while(left<right){
                if(nums[left]+nums[right]>target){
                    right--;
                }
                else if(nums[left]+nums[right]<target){
                    left++;
                }else{
                    ans.push_back({nums[i],nums[left],nums[right]});
                    left++;
                    right--;
                    while(left<right && nums[left]==nums[left-1])
                        left++;
                    while(left<right &&nums[right]==nums[right+1])
                        right--;
                }
            }
        }
        return ans;
    }
};
```

### √11.盛水最多的容器 贪心+左右双指针
```c++
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        while (left < right)
        {
            auto tmp = (right - left) * min(height[right], height[left]);
            ans = max(ans, tmp);
            if (height[right] < height[left])
                right--;
            else
                left++;
        }
        return ans;
    }
};
```

### √42.接雨水NEED
左右扫两次最大为pre和suf，前后缀取最小减去当前值

```c++
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> pre(n),suf(n);
        pre[0]=height[0];
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i]);
        }
        suf[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){       //i=1 or 0
            ans+=min(pre[i],suf[i])-height[i];
        }
        return ans;
    }
};
```

## 滑窗
### 3.无重复的最长字串
```c++
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char> Map;
        int ans=0,left=0;
        for(int right=0;right<n;right++){
            if(Map.find(s[right]) == Map.end()){
                ans=max(ans,right-left+1);
                Map.insert(s[right]);
            }
            else{
                while(Map.find(s[right]) != Map.end()){
                    Map.erase(s[left++]);
                }
                ans=max(ans,right-left+1);
                Map.insert(s[right]);
            }
        }
        return ans;
    }
};
```

### 438.找到字符串中所有字母异位词

```c++
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> res;
        if (s.size() < p.size())
            return res;
        vector<int> p_count(26, 0), s_count(26, 0);
        for (char c : p)
            p_count[c - 'a']++;
        for (int i = 0; i < p.size(); i++)
            s_count[s[i] - 'a']++;
        if (s_count == p_count)
            res.push_back(0);
        for (int i = p.size(); i < s.size(); i++)
        {
            s_count[s[i] - 'a']++;
            s_count[s[i - p.size()] - 'a']--;
            if (s_count == p_count)
                res.push_back(i - p.size() + 1);
        }
        return res;
    }
};
```
## 子串
### 560.和为 K 的子数组  
```c++
class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefix;
        int curSize = 0;
        int ans = 0;
        prefix[0] = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            curSize += nums[i];
            if (prefix.find(curSize - k) != prefix.end())
                ans += prefix[curSize - k];
            prefix[curSize]++;
        }
        return ans;
    }
};
```
### 239.滑动窗口最大值  
```c++
// 这题的难度在于，前最大值滑出滑窗时，你不知道是否有重复值或者次大值、
// 想象成nums[]是以恶搞index，那么用单调队列存下标的方式来做历史排序。
class Solution
{
public:
    map <int,int> Map;
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> que;
        for(int i=0;i<k;i++){
            while(!que.empty()&&nums[i]>=nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
        }
        ans.push_back(nums[que.front()]);

        for(int i=k;i<nums.size();i++){
            if(que.front() <= i-k)
                que.pop_front();
            while(!que.empty() && nums[i]>=nums[que.back()]){
                que.pop_back();
            }
            que.push_back(i);
            ans.push_back(nums[que.front()]);
        }
        return ans;

    }
};
```
### 76.最小覆盖子串
```c++
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int need[128] = {0}, window[128] = {0};
        int needValid = 0;
        for (char c : t)
        {
            if (need[c] == 0)
                needValid++;
            need[c]++;
        }
        int valid = 0, left = 0, ansLeft = -1, ansLen = INT_MAX;
        for (int right = 0; right < s.size(); right++)
        {
            char c = s[right];
            window[c]++;
            if (window[c] == need[c])
                valid++;
            while (valid == needValid)
            {
                if (right - left + 1 < ansLen)
                {
                    ansLen = right - left + 1;
                    ansLeft = left;
                }
                char cLeft = s[left];
                window[cLeft]--;
                if (window[cLeft] < need[cLeft])
                    valid--;
                left++;
            }
        }
        return ansLeft == -1 ? "" : s.substr(ansLeft, ansLen);
    }
};
```

## 普通数组

### 53.最大子数组和  
```c++
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int minPre=0,ans=INT_MIN,Pre=0;
        for(auto num: nums){
            Pre+=num;
            ans=max(ans,Pre-minPre);
            minPre=min(Pre,minPre);
        }
        return ans;
    }
};
```
### 56.合并区间  
```c++
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        if (intervals.empty())
        {
            return {};
        }
        // 1. 按区间的左端点排序
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]); // 先放入第一个区间
        // 2. 遍历并合并
        for (int i = 1; i < intervals.size(); ++i)
        {
            vector<int> &last = ans.back();      // 结果中的最后一个区间
            vector<int> &current = intervals[i]; // 当前要处理的区间
            if (current[0] <= last[1])
            {
                last[1] = max(last[1], current[1]);
            }
            else
            {
                ans.push_back(current);
            }
        }
        return ans;
    }
};
```
### 189.轮转数组
```c++
class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n == 0)
            return;
        // 1. 处理 k > n 的情况
        k = k % n;
        if (k == 0)
            return;
        // 2. 三次反转
        // a. 整体反转
        reverse(nums.begin(), nums.end());
        // b. 反转前 k 个元素
        reverse(nums.begin(), nums.begin() + k);
        // c. 反转后 n-k 个元素
        reverse(nums.begin() + k, nums.end());
    }
};
```
### 238.除了自身以外数组的乘积  
```c++
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> answer(n);
        // 步骤 1: 计算每个位置左边的乘积
        // answer[i] = nums[0] * nums[1] * ... * nums[i-1]
        answer[0] = 1;
        for (int i = 1; i < n; ++i)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }
        // 步骤 2: 从右到左遍历，乘以右边的乘积
        // 同时计算右边的乘积
        int right = 1; // right 表示 nums[i+1] * nums[i+2] * ... * nums[n-1]
        for (int i = n - 1; i >= 0; --i)
        {
            // answer[i] 现在等于 left[i] * right
            answer[i] = answer[i] * right;
            // 更新右边乘积，为下一轮迭代准备
            right *= nums[i];
        }
        return answer;
    }
};
```
### 41.缺失的第一个正数
```c++
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        // 步骤 1: 将每个数字放到它应该在的位置
        // 数字 x 应该在下标 x-1
        for (int i = 0; i < n; ++i)
        {
            // 只处理 [1, n] 范围内的数字
            // 循环交换直到 nums[i] 不在 [1, n] 或已经在正确位置
            while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1])
            {
                // 交换 nums[i] 和 nums[nums[i]-1]
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // 步骤 2: 找第一个不在正确位置的数字
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        // 步骤 3: 所有 [1, n] 都在正确位置，答案是 n+1
        return n + 1;
    }
};
```
## 矩阵
### 73.矩阵置零  
```c++
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;

        // 步骤1: 记录原始首行首列是否有0
        for (int j = 0; j < n; ++j)
            if (matrix[0][j] == 0)
                firstRowZero = true;

        for (int i = 0; i < m; ++i)
            if (matrix[i][0] == 0)
                firstColZero = true;

        // 步骤2: 用首行首列做标记
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                                }

        // 步骤3: 根据标记清零内部
        for (int i = 1; i < m; ++i)
            for (int j = 1; j < n; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;

        // 步骤4: 最后处理首行首列本身
        if (firstRowZero)
            for (int j = 0; j < n; ++j)
                matrix[0][j] = 0;

        if (firstColZero)
            for (int i = 0; i < m; ++i)
                matrix[i][0] = 0;
    }
};
```
### 54.螺旋矩阵  
```c++
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
            return {};
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;
        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;
        while (top <= bottom && left <= right)
        {
            // 从左到右遍历上边
            for (int j = left; j <= right; j++)
            {
                ans.push_back(matrix[top][j]);
            }
            top++;
            // 从上到下遍历右边
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(matrix[i][right]);
            }
            right--;
            // 从右到左遍历下边（需要检查是否还有行）
            if (top <= bottom)
            {
                for (int j = right; j >= left; j--)
                {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }
            // 从下到上遍历左边（需要检查是否还有列）
            if (left <= right)
            {
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};
```
### 48.旋转图像
```c++
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        // 1) 转置
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        // 2) 每行反转
        for (int i = 0; i < n; ++i)
        {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```
### 240.搜索二维矩阵 II  
```c++
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() || matrix[0].empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        // 从右上角开始
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            if (matrix[i][j] == target)
            {
                return true;
            }
            else if (matrix[i][j] > target)
            {
                // 当前元素太大，向左移动
                j--;
            }
            else
            {
                // 当前元素太小，向下移动
                i++;
            }
        }
        return false;
    }
};
```
## 链表

### 160.相交链表  
```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        for (ListNode *p = headA; p != nullptr; p = p->next) {
            for (ListNode *q = headB; q != nullptr; q = q->next) {
                if (p == q)
                    return p;
            }
        }
        return nullptr;
    }
};
```
### 206.反转链表  
```c++
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr,*tmp=head;
        while(tmp){
            auto nxt=tmp->next;
            tmp->next=pre;
            pre=tmp;
            tmp=nxt;
        }
        return pre;
    }
};
```
### 234.回文链表
```c++
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> valsHalf;
        ListNode* slow=head;
        while(slow!=nullptr){
            valsHalf.push_back(slow->val);
            slow=slow->next;
        }

        for (int i = 0, j = (int)valsHalf.size() - 1; i < j; ++i, --j) {
            if (valsHalf[i] != valsHalf[j]) {
                return false;
            }
        }
        return true;
    }
};
```
### 141.环形链表  
```c++
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
```
### 142.环形链表 II  （需要背，相当于二元一次方程）
```c++
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
```
### 21.合并两个有序链表  
```c++
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0, nullptr);
        ListNode *tmp = &dummy;
        while (list1 && list2)
        {
            if (list1->val > list2->val)
            {
                tmp->next = list2;
                tmp = tmp->next;
                list2 = list2->next;
            }
            else
            {
                tmp->next = list1;
                tmp = tmp->next;
                list1 = list1->next;
            }
        }
        tmp->next = list1 == nullptr ? list2 : list1;
        return dummy.next;
    }
};
```
### 2.两数相加  
```c++
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
```
### 19.删除链表的倒数第 N 个结点  
```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* first = head;
        ListNode* second = dummy;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;

    }
};
```
### 24.两两交换链表中的节点  
```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyHead = new ListNode(0); // 设置一个虚拟头结点
        dummyHead->next = head; // 将虚拟头结点指向head，这样方便后面做删除操作
        ListNode* cur = dummyHead;
        while(cur->next != nullptr && cur->next->next != nullptr) {
            ListNode* tmp = cur->next; // 记录临时节点
            ListNode* tmp1 = cur->next->next->next; // 记录临时节点

            cur->next = cur->next->next;    // 步骤一
            cur->next->next = tmp;          // 步骤二
            cur->next->next->next = tmp1;   // 步骤三

            cur = cur->next->next; // cur移动两位，准备下一轮交换
        }
        ListNode* result = dummyHead->next;
        delete dummyHead;
        return result;
    }
};
```
### 25.K 个一组翻转链表  
```c++
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode* tmp=head;
        while(tmp!=nullptr){
            n++;
            tmp=tmp->next;
        }
        
        ListNode dummy(0,head);
        ListNode* p0=&dummy, *pre=nullptr;
        tmp=head;
        for(;n>=k;n-=k){
            for(int i=0;i<k;i++){
                auto nxt=tmp->next;
                tmp->next=pre;
                pre=tmp;//2
                tmp=nxt;//3
            }
            auto NextP0=p0->next;
            p0->next=pre;
            p0=NextP0;
            NextP0->next=tmp;
        }
        return dummy.next;
    }
};
```
### 138.随机链表的复制  
```c++
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == nullptr) return nullptr;
        Node* cur = head;
        unordered_map<Node*, Node*> map;
        while(cur != nullptr) {
            map[cur] = new Node(cur->val);
            cur = cur->next;
        }
        cur = head;
        while(cur != nullptr) {
            map[cur]->next = map[cur->next];
            map[cur]->random = map[cur->random];
            cur = cur->next;
        }
        return map[head];
    }
};
```
### 148.排序链表  
```c++
class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        // 快慢指针找中点
        ListNode *slow = head, *fast = head, *prev = nullptr;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr; // 断开链表
        ListNode *l1 = sortList(head);
        ListNode *l2 = sortList(slow);
        return merge(l1, l2);
    }

    ListNode *merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummy(0);
        ListNode *tail = &dummy;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;
        return dummy.next;
    }
};
```
### 23.合并 K 个升序链表  
```c++
class Solution {
public:
    ListNode* mergeSort(vector<ListNode*>& lists, int left,int right){
        if(left>right)
            return nullptr;
        if(left==right)
            return lists[left];
        int mid=left+(right-left)/2;
        auto leftNode=mergeSort(lists,left,mid);
        auto RightNode=mergeSort(lists,mid+1,right);
        ListNode dummy(0,nullptr);
        ListNode* tmp=&dummy;
        while(leftNode && RightNode){
            if(leftNode->val < RightNode->val){
                tmp->next=leftNode;
                leftNode=leftNode->next;
                tmp=tmp->next;
            }else{
                tmp->next=RightNode;
                RightNode=RightNode->next;
                tmp=tmp->next;
            }
        }
        tmp->next=leftNode?leftNode:RightNode;
        return dummy.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())
            return nullptr;
        auto ans=mergeSort(lists,0,lists.size()-1);
        return ans;
    }
};
```
### 146.LRU 缓存
```c++
class LRUCache {
public:
    int _capacity;
    unordered_map<int,list<pair<int,int>>::iterator>Map;
    list<pair<int,int>> Cache;
    LRUCache(int capacity):_capacity(capacity) {}
    
    int get(int key) {
        auto it=Map.find(key);
        if(it!=Map.end()){
            //hit
            auto value=it->second->second;
            Cache.erase(it->second);
            Cache.push_front({key,value});
            Map[key]=Cache.begin();//point
            return value;
        }
        else    
            return -1;
    }
    
    void put(int key, int value) {
        auto it=Map.find(key);
        if(it!=Map.end()){
            //hit
            Cache.erase(it->second);
            Cache.push_front({key,value});
            Map[key]=Cache.begin();//point
            return;
        }
        else{
            Cache.push_front({key,value});
            Map[key]=Cache.begin();//point
            if(_capacity<Cache.size()){
                auto rm=Cache.back();
                Map.erase(rm.first);
                Cache.pop_back();
            }
        }  
    }
};
```

## 二叉树

### 94.二叉树的中序遍历  
```c++
```cpp
class Solution {
public:
    vector<int> ans;
    void loop(TreeNode* node){
        if(node==nullptr)
            return;
        loop(node->left);
        ans.push_back(node->val);
        loop(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        loop(root);
        return ans;
    }
};
```
### 104.二叉树的最大深度
```c++
class Solution
{
public:
    int ans = 0;
    void Loop(TreeNode *Father, int tmp)
    {
        if (Father->left)
        {
            Loop(Father->left, tmp + 1);
        }
        if (tmp + 1 > ans)
            ans = tmp + 1;
        if (Father->right)
        {
            Loop(Father->right, tmp + 1);
        }
    }
    int maxDepth(TreeNode *root)
    {
        if (root)
            Loop(root, 0);
        return ans;
    }
};
```
### 226.翻转二叉树  

```c++
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        TreeNode *temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};
```

### 101.对称二叉树
```cpp
class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
```
### 543.二叉树的直径  

```cpp
class Solution
{
private:
    int maxDiameter = 0;

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        // 递归计算左右子树的深度
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // 经过当前节点的路径长度 = 左深度 + 右深度
        // 用它来更新全局最大直径
        maxDiameter = std::max(maxDiameter, leftDepth + rightDepth);

        // 返回当前节点的深度 = 左右子树深度的较大值 + 1
        return std::max(leftDepth, rightDepth) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        maxDepth(root);
        return maxDiameter;
    }
};
```
### 102.二叉树的层序遍历  
```cpp
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        deque<TreeNode *> nodes;
        vector<vector<int>> ans;
        nodes.push_back(root);
        while (!nodes.empty())
        {
            auto curSize = nodes.size();
            vector<int> path;
            for (int i = 0; i < curSize; i++)
            {
                auto tmpnode = nodes.front();
                path.push_back(tmpnode->val);
                nodes.pop_front();
                if (tmpnode->left)
                    nodes.push_back(tmpnode->left);
                if (tmpnode->right)
                    nodes.push_back(tmpnode->right);
            }
            ans.push_back(path);
        }
        return ans;
    }
};
```

### 108.将有序数组转换为二叉搜索树  
```c++
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildBST(const vector<int> &nums, int left, int right)
    {
        // 当左边界大于右边界时，说明子数组为空，返回nullptr
        if (left > right)
        {
            return nullptr;
        }

        // 找到中间位置的索引
        int mid = left + (right - left) / 2;

        // 创建根节点
        TreeNode *root = new TreeNode(nums[mid]);

        // 递归构建左子树
        root->left = buildBST(nums, left, mid - 1);

        // 递归构建右子树
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};
```
### 98.验证二叉搜索树  
```c++
class Solution {
public:
    long long pre = LLONG_MIN; 
    bool isValid=true;
    void bfs(TreeNode* root){
        if(isValid){
            if(root->left)
                bfs(root->left);

            if(root->val > pre)
                pre= root->val;
            else 
                isValid=false;

            if(root->right)
                bfs(root->right);
        }
        else 
            return;
    }
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        bfs(root);
        return isValid;
    }
};
```
### 230.二叉搜索树中第 K 小的元素  
```c++
class Solution {
public:
    int count=0;
    int ans;
    void dfs(TreeNode* root, int k){
        if(count==k)return;

        if(root->left){
            dfs(root->left,k);
        }
        count++;
        if(count==k)
            ans=root->val;
        
        if(root->right){
            dfs(root->right,k);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
};
```
### 199.二叉树的右视图  
```c++
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        deque<TreeNode* > q;
        if(root==nullptr)
            return {};
        else 
            q.push_back(root);
        while(!q.empty()){
            auto size= q.size();

            for(int i=0;i<size;i++){
                auto tmp=q.front();
                q.pop_front();
                if(tmp->left)
                    q.push_back(tmp->left);
                if(tmp->right)
                    q.push_back(tmp->right);
                if(i==size-1){
                  ans.push_back(tmp->val);
                }
            }

        }
        return ans;
    }
};
```
### 114.二叉树展开为链表  
```c++
class Solution {
public:
    TreeNode * head=nullptr;
    
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        flatten(root->right);
        flatten(root->left);

        root->left =nullptr;
        root->right =head;
        head=root;
    }
};
```
### 105.从前序与中序遍历序列构造二叉树  
```c++
class Solution {
public:
    unordered_map<int, int> InKey2Index;
    TreeNode* dfs(int PreRoot, int InLeft, int InRight, vector<int>& preorder){
        if (InLeft > InRight) {
            return nullptr;
        }
        int InRootIndex = InKey2Index[preorder[PreRoot]];
        int LeftOffset = InRootIndex - InLeft;
        int RightOffset = InRight - InRootIndex;
        TreeNode* left= dfs(PreRoot+1,InLeft,InRootIndex-1,preorder);
        TreeNode* right=dfs(PreRoot+1+LeftOffset,InRootIndex+1,InRight,preorder);
        return new TreeNode(preorder[PreRoot],left,right);
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        int n= preorder.size();
        for(int i =0; i<n;i++){
            InKey2Index[inorder[i]]=i;
        }
        return dfs(0, 0, n-1, preorder);
    }
};
```
### 437.路径总和 III  
```c++
class Solution {
public:
    unordered_map<long long , int > cnt={{0,1}};
    int ans=0;
    long long Path=0;
    void dfs(TreeNode* root , int t){
        if(!root){
            return ;
        }
        Path+=root->val;
        ans+=cnt[Path-t];
        cnt[Path]++;
        dfs(root->left, t);
        dfs(root->right,t);
        cnt[Path]--;
        Path-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        dfs(root,targetSum);
        return ans;

    }
};
```
### 236.二叉树的最近公共祖先  
```c++
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        // 1. 终止条件
        if (root == nullptr || root == p || root == q)
        {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left != nullptr && right != nullptr)
            return root; // ans
        if (left != nullptr)
            return left; // 1/2*ans
        else
            return right; // 1/2*ans
    }
};
```
### 124.二叉树中的最大路径和
```c++
class Solution {
public:
    int path;
    int ans= INT_MIN;
    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }
        int left= dfs(root->left);
        int right=dfs(root->right);
        ans=max(ans, left+right+root->val);
        return max(0,max(left,right)+root->val);// only root->val的情况被子级的return 0包含了
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
```