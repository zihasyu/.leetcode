## 技巧(5/5)
###  136.只出现一次的数字（异或）
```c++
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto num:nums){
            ans^=num;
        }
        return ans;
    }
};
```

###  169.多数元素（超半元素，打擂台）
```c++
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=nums[0],numbers=1;
        for(int i=1;i<nums.size();i++){
            if(ans==nums[i]){
                numbers++;
            }
            else{
                if(numbers!=0){
                    numbers--;
                }
                else{
                    numbers++;
                    ans=nums[i];
                }
            }
        }
        return ans;
    }
};
```

### 75.颜色分类（三个指针，012排序）

```c++
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p0=0,p1=0;
        for(auto & num: nums){
            auto tmp=num;
            num=2;
            if(tmp==1){
                nums[p1++]=1;
            }
            if(tmp==0){
                nums[p1++]=1;
                nums[p0++]=0;
            }
        }
        return;
    }
};
```

### 31.下一个排列（swap+reverse）不容易记住的题

```c++
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        while(i>=0 && nums[i]>=nums[i+1]){
            i--;
        }
        if(i>=0){
            int j=n-1;
            while(nums[j]<=nums[i])j--;
            swap(nums[i],nums[j]);
            reverse(nums.begin()+i+1,nums.end());
        }else{
            reverse(nums.begin(),nums.end());
        }
    }
};
```

### 287.寻找重复数（本质是快慢指针II）
```c++
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        do {
            slow = nums[slow];    
            fast = nums[nums[fast]];  
        } while (slow != fast);
        
        slow = 0;
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
```

## 多维动态规划（主要是字符串的动规）(-/5)
### 62.不同路径（组合数学也可以解）
```c++
class Solution {
public:
long long comb(int n, int k) {
        k = min(k, n - k);
        long long res = 1;
        for (int i = 0; i < k; i++) {
            // res = res * (n + 1 - i) / i;
            res*=(n-i);
            res/=(i+1);
        }
        return res;
    }

    int uniquePaths(int m, int n) {
        int x=m-1,y=n-1;
        return comb(x+y,x);
    }
};
```

```c++
class Solution {
public:
	//二维dp
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i&&j){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }else{
                    if(i+j==0)continue;
                    if(!j){
                        dp[i][j]=dp[i-1][j];
                    }else{
                        dp[i][j]=dp[i][j-1];
                    }
                }
            }
        }
        return dp[m-1][n-1];
    }
    //省空间压缩一维
    int uniquePaths(int m, int n) {
        vector<int> f(n + 1);
        f[1] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                f[j + 1] += f[j];
            }
        }
        return f[n];
    }

};
```

### 64.最小路径和（二维动规可以压一维空间）
```c++
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        // 二维
        // vector dp(m+1, vector<int> (n+1,INT_MAX));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         if(i==0 && j==0)
        //             dp[1][1]=grid[0][0];
        //         else{
        //             dp[i+1][j+1]=min(dp[i][j+1],dp[i+1][j])+grid[i][j];
        //         }
        //     }
        // }
        // return dp[m][n];
        
        //压一维
        vector<int> dp(n+1,INT_MAX);
        dp[1]=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                dp[j+1]=min(dp[j],dp[j+1])+grid[i][j];
            }
        }
        return dp[n];
    }
};
```

### 5.最长回文串（中心扩散，奇偶分开各一次）

```c++
class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();
        int ans_left=0,ans_right=0;
        for(int i=0;i<s.size();i++){
            int left=i,right=i;
            while(left>=0&&right<=n-1 && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-2>ans_right-ans_left){
                ans_left=left+1;
                ans_right=right-1;
            }
        }

        for(int i=0;i<s.size();i++){
            int left=i,right=i+1;
            while(left>=0&&right<=n-1 && s[left]==s[right]){
                left--;
                right++;
            }
            if(right-left-2>ans_right-ans_left){
                ans_left=left+1;
                ans_right=right-1;
            }
        }
        return s.substr(ans_left,ans_right-ans_left+1);
    }
};
```

### 1143. 最长公共子序列（二维动规可以压一维空间）
```c++
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
		int m=text1.size(), n=text2.size();
		// vector dp(m+1,vector<int>(n+1));
		// for(int i=1;i<=m;i++){
		// 	for(int j=1;j<=n;j++){
		// 		dp[i][j]=max(max(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]+(text1[i-1]==text2[j-1]));
		// 	}
		// }
		// return dp[m][n];
		
		
        vector<int> dp(n+1,0);
        for(int i=0;i<m;i++){
            int pre=0;//左上角 i-1, j-1
            for(int j=0;j<n;j++){
                auto tmp=dp[j+1];
                dp[j+1]= max(pre+ (text1[i]==text2[j]),
                max(dp[j],dp[j+1])
                );
                pre=tmp;
            }
        }
        return dp[n];
    }
};
```

### 72.编辑距离 与64.1143是一类题（min动规）

```c++
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m=word1.size(),n=word2.size();
        vector dp(m+1,vector<int>(n+1,0));
        for (int i = 0; i <= m; i++) dp[i][0] = i; // 删除操作
        for (int j = 0; j <= n; j++) dp[0][j] = j; // 插入操作
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                dp[i+1][j+1]=min(dp[i][j]+1-(word1[i]==word2[j]),
                min(dp[i+1][j]+1,dp[i][j+1]+1)
                );
            }
        }
        return dp[m][n];
    }
};
```

## 动规(-/10)

### 70.爬楼梯(Eazy累加数)

```c++
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1,dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
```

### 118.杨辉三角(Eazy累加数)

```c++
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector ans(numRows,vector<int>(1,1));
        for (int i = 0; i < numRows; i++) {
            ans[i].resize(i + 1, 1);
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }
        return ans;
    }
};
```

### 198.打家劫舍（max一维动规）

```c++
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+2);
        for(int i=0;i<n;i++){
            dp[i+2]=max(dp[i]+nums[i],dp[i+1]);
        }
        return dp[n+1];
    }
};
```

### 279.完全平方数（min一维动规）

```c++
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],dp[i-j*j]+1);
            }
        }
        return dp[n];
    }
};
```

### 322.零钱兑换（min一维动规，注意不要整数溢出）

`if(dp[j-coins[i]]!=INT_MAX)`279不需要的原因是279的所有值一定可达，而零钱不一定

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector <int> dp(amount+1,INT_MAX);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
		    for(int j=coins[i];j<=amount;j++){
                if(dp[j-coins[i]]!=INT_MAX)
				    dp[j]=min(dp[j-coins[i]]+1,dp[j]);
			}
	    }
        return dp[amount]==INT_MAX?-1 :dp[amount];
    }
};
```

### ×139. 单词拆分（HARD 完全背包+排列）
两个非常规组合在一起
排列数先背包后物品 + 完全背包二层正序

```c++
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> Set(wordDict.begin(),wordDict.end());
        int n=s.size();
        vector<bool> dp(n+1);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            //前i个字符是否true
            for(int j=0;j<i;j++){
                //从j来看前i个字符 是否true
                if(dp[j] && Set.find(s.substr(j,i-j))!=Set.end()){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```

### 300.最长递增子序列（可以贪心lower_bound）
用`lower_bound(tmp.begin(),tmp.end(),num)）`

```c++
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        for(auto num: nums){
            auto it=lower_bound(tmp.begin(),tmp.end(),num);
            if(it==tmp.end())
                tmp.push_back(num);
            else{
                *it=num;
            }
        }
        return tmp.size();
    }
};
```

### 152.乘积最大子数组（正负两列的动规）用到ranges::

```c++
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> dpMax(n),dpMin(n);
        dpMax[0]=dpMin[0]=nums[0];
        for(int i=1;i<n;i++){
            auto tmp=nums[i];
            dpMax[i]=max({tmp,dpMax[i-1]*tmp,dpMin[i-1]*tmp});
            dpMin[i]=min({tmp,dpMax[i-1]*tmp,dpMin[i-1]*tmp});
        }
        return ranges::max(dpMax);
    }
};
```

### 416.分割等和子集 （0-1背包）

先物品后背包（组合数）+倒序二层（0-1背包，每个num使用一次）
```c++
class Solution{
public :
	bool canPartition(const vector<int>& nums){
		int sum= reduce(nums.begin(),nums.end());
		if(sum%2)
			return false;
		vector<bool> dp(sum/2 + 1,false);
		dp[0]=true;
		for(int i=0;i<nums.size();i++){
			for(int j=sum/2;j>=nums[i];j--){
				if(dp[j-nums[i]]==true)
					dp[j]=true;
			}
		}
		return dp[sum/2];
	}
};
```

### 32.最长有效括号（动规or左右扫描取最大）
动规：
```c++
class Solution{
public:
    int longestValidParentheses(string s)
    {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            if (s[i] == ')')
            {
                if (s[i - 1] == '(')
	            //...()
                    if (i - 2 >= 0)
                        dp[i] = dp[i - 2] + 2;
                    else
                        dp[i] = 2;
                else
                //...))
                {
                    int leftIndex = i - dp[i - 1] - 1;
                    if (leftIndex >= 0 && s[leftIndex] == '(')
                    {
                        dp[i] = dp[i - 1] + 2;
                        if (leftIndex > 0)
                            dp[i] += dp[leftIndex - 1];
                    }
                    else
                        dp[i] = 0;
                }
            }
        }
        return ranges::max(dp);
    }
};
```

左右扫描
```c++
class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int ans=0,left=0,right=0;
        for(auto c:s){
            if(c=='(')
                left++;
            else 
                right++;
            if(left<right){
                left=0;
                right=0;
            }else if(right==left){
                ans=max(ans,right*2);
            }
        }

        left=right=0;
        for(int i=s.length()-1;i>=0;i--){
            auto c=s[i];
            if(c==')')
                right++;
            else 
                left++;
            if(left>right){
                left=0;
                right=0;
            }else if(right==left){
                ans=max(ans,left*2);
            }
        }
        return ans;
    }
};
```


## 贪心 (2/4)

### √121.买卖股票的最佳时机 
//只记录最小值的贪心即可（因为最大值可能在之前而不是之后），另外先更新ans，再更新Min，防止一直跌的时候ans=0;
```c++
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int ans=INT_MIN,Min=prices[0];
		for(auto p:prices){
			ans=max(ans,p-Min);
			Min=min(Min,p);
		}
		return ans;
    }
};

```

### √55.跳跃游戏

```c++
class Solution {
public:
   bool canJump(vector<int>& nums) {
		int n=nums.size();
		int Max=0;
		for(int i=0;i<n;i++){
			if(Max<i)return false;
			Max=max(Max,i+nums[i]);
		}
		return true;
    }
};

```

### 45.跳跃游戏2（&& i<n-1容易写错）

`i==n-1时是终点，容易多跳一步`

```c++
class Solution {
public:
    int jump(vector<int>& nums) {
        int preMax=0,nextMax=0;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
	        nextMax=max(nextMax,i+nums[i]);
	        if(i==preMax && i<n-1){//i==n-1时是终点，容易多跳一步
		        ans++;
		        preMax=nextMax;
	        }
        }
        return ans;
    }
};
```

### ×763.NEED 划分字母区间（本质数组贪心题，合并区间）

开个map只看最右坐标即可

```c++
class Solution {
public:
    vector<int> partitionLabels(string s) {
		unordered_map<char,int> Map;
		int index=0;
		for(auto c:s){
			Map[c]=index++;
		}
		int end=0,tmpSize=0;
		vector<int> ans;
		
        for(int i=0;i<s.size();i++){
            auto tmp=Map[s[i]];
            end=max(end,tmp);
            tmpSize++;
            
            if(end==i){
                ans.push_back(tmpSize);
                tmpSize=0;
            }
        }
		return ans;
    }
};
```

## 堆Heap(2/3)

### √215.数组的第k个最大元素（快速选择算法+递归）
```c++
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
		int randomIndex=rand()%nums.size();
		int random=nums[randomIndex];
		vector<int> large,small,equal;
		for(auto num: nums){
			if(num<random)
				small.push_back(num);
			else if (num==random){
				equal.push_back(num);
			}else{
				large.push_back(num);
			}
		}
		if(large.size()>=k)
			return findKthLargest(large,k);
		else if(large.size()<k  && large.size()+equal.size()>=k)
			return random;
		else{
			return findKthLargest(small,k-large.size()-equal.size());
		}
    }
};
```

### √×347.前k个高频元素(小根堆√，桶排序匚1用到insert)

自定义小根堆
```c++
class Solution {
public:
    struct Newcompare{
        bool operator()(const pair<int,int> a, const pair<int,int>b)
        {
            return a.second > b.second;
        }
    };
   
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++) {
            map[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Newcompare> q;
        for(auto m: map){
            q.push(m);
            if(q.size()>k)
                q.pop();
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};
```

桶排序：把kv倒过来当作桶
```c++
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> Map;
        int maxSize=0;
        for(auto num:nums){
            Map[num]++;
            maxSize=max(maxSize,Map[num]);
        }
        vector<vector<int>> bucket(maxSize+1);
        
        for(auto it: Map){
            bucket[it.second].push_back(it.first);
        }
        vector<int> ans;

        for(int i=maxSize;ans.size()<k;i--){
            ans.insert(ans.end(), bucket[i].begin(), bucket[i].end());
        }
        return ans;
    }
};
```

### √295.数据流的中位数（结构体+最大最小双堆）

```c++
class MedianFinder {
public:
    priority_queue<int> MaxQ;
    priority_queue<int,vector<int>,greater<int>> MinQ;
    int Size=0;
    MedianFinder() {}
    
    void addNum(int num) {
        Size++;
        if(Size%2){
            MaxQ.push(num);
            auto tmp=MaxQ.top();
            MinQ.push(tmp);
            MaxQ.pop();
        }else{
            MinQ.push(num);
            auto tmp=MinQ.top();
            MaxQ.push(tmp);
            MinQ.pop();
        }
    }
    
    double findMedian() {
        if(Size%2){
            return MinQ.top();
        }
        else{
            return ((double)MinQ.top()+(double)MaxQ.top())/2;
        }
    }
};

```

## 栈Stack (1/5)  重灾区

### √20.有效的括号（st.empty() ||也是false条件）

```c++
class Solution {
public:
    unordered_map<char,char> Map={{'(',')'}, {'[',']'},{'{','}'} };
    bool isValid(string s) {
        stack<char> st;
        for(auto c:s){
            if(Map.find(c)!=Map.end())
                st.push(Map[c]);
            else{
                if(st.empty() || st.top()!=c)
                    return false;
                st.pop();
            }
        }
        if(st.empty())
            return true;
        else 
            return false;
    }
};
```

### ×155.NEED最小栈，栈的拓展结构题

```c++
class MinStack {
public:
    stack<pair<int,int>> st;
    int CurSize=0;

    MinStack() {
        st.push({INT_MAX,INT_MAX});
    }
    
    void push(int val) {
        int MinVal=min(val,st.top().second);
        st.push({val,MinVal});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
```

### ××394.NEED字符串解码（可以嵌套，处理比较麻烦，需仔细）

```c++
class Solution {
public:
    int index=0;
    string decode(string s){
        string ans;
        int k=0;
        while(index<s.size()){
	        auto c=s[index];
	        index++;
	        if(isalpha(c)){
		        ans+=c;
	        }
	        else if('0'<=c && c<='9'){
		        k*=10;
		        k+=c-'0';
	        }else if(c=='['){
		        auto subS=decode(s);
		        for(;k>0;k--){
			        ans+=subS;
		        }
	        }else break;
        }
        return ans;
    }
    string decodeString(string s) {
        return decode(s);
    }
};
```

### ×739.每日温度 （St中是index而不是value，经典模型NEED）


```c++
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=temperatures.size();
        vector<int> ans;
        stack<int> st;
       for(int i=n-1;i>=0;i--){
           auto t=temperatures[i];
           while(!st.empty() && t>=temperatures[st.top()]){
                st.pop();
           }
           if(!st.empty())
                ans.push_back(st.top()-i);
            else 
                ans.push_back(0);
            st.push(i);
       }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

```
### ×84.柱状图中的最大矩形

```c++
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> left(n, -1);   // 意义是左边比他小的元素，默认左边没更小的，设为 -1
        vector<int> right(n, n);   // 意义是右边比他小的元素，默认右边没更小的，设为 n
        for(int i = 0; i < n; ++i){
            auto h = heights[i];
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty())
                left[i]=st.top();
            st.push(i);
        }
        // st.clear();
        while (!st.empty()) 
	        st.pop();
        for(int i=n-1;i>=0;i--){
            auto h=heights[i];
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty())
                right[i]=st.top();
            st.push(i);
        }
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, heights[i] * (right[i] - left[i] - 1));
        }
        return ans;
    }
};
```

## 二分（3/6）

### √35.搜索插入位置（直白二分）

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
    }
};
```

### √74.搜索二维数组（取模的直白二分）

```c++
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
             return false;
        int m=matrix.size(),n=matrix[0].size();
        int left=0,right=m*n-1;
        while(left<=right){
            int mid=(left+right)/2;
            int x=matrix[mid/n][mid%n];
            if(x==target)return true;
            else if(x>target){right=mid-1;}
            else{left=mid+1;}
        }
        return false;
    }
};
```

### √34.在排序数组中查找元素的第一个和最后一个位置（红蓝染色，本质把二分的相等处理修改）

```c++
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]==target)right=mid-1;
            else if(nums[mid]>target){
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return left;
        }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=searchInsert(nums,target);
        int end=searchInsert(nums,target+1);
        if(start<0 || start>=nums.size()||nums[start]!=target)
            return {-1,-1};
        return {start,end-1};
    }
};
```

### ×33.搜索旋转排序数组NEED


```c++
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[mid] < nums[right])
            {
                // mid in right line
                if (nums[mid] < target && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
            else
            {
                if (nums[left] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};
```

### ×153.寻找旋转排序数组中的最小值NEED

框架没问题，边界写的有问题

```c++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        int RightEnd=nums[right];
        
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]<=RightEnd){//这个边界
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return nums[left];
    }
};
```

### ××4.寻找两个正序数组的中位数 HARD
1. 二分的数组必须是小数组，否则第二个数组容易越界
2. 对第一个数组的right=m这个边界很麻烦，因为切分可能在最右边和最左边
3. i_left, i_right这些更麻烦。

```c++
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            return findMedianSortedArrays(nums2,nums1);

        int m=nums1.size(),n=nums2.size();
        int left=0,right=m;//这个边界很难
        int total=m+n;
        int mid=(total+1)/2;

        while(left<=right){
            int i=(left+right)/2;
            int j=mid-i;

            double i_left= (i==0)?INT_MIN:nums1[i-1];
            double i_right= (i==m)? INT_MAX:nums1[i];
            double j_left= (j==0)?INT_MIN:nums2[j-1];
            double j_right= (j==n)? INT_MAX:nums2[j];

            if(i_left<=j_right && j_left<=i_right){
                if(total%2){
                    return max(i_left,j_left);
                }else{
                    return (max(i_left,j_left)+min(i_right,j_right))/2;
                }
            }else if(i_left>j_right){
                right=i-1;
            }else{
                left=i+1;
            }
        }
        return 0.0;
    }
};
```

## 回溯（/8）

### √46.全排列 （排列全局used+size满）

```c++
class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<bool> used;
    void dfs(const vector<int>& nums){
        if(path.size()==nums.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                used[i]=false;
                path.push_back(nums[i]);
                dfs(nums);
                path.pop_back();
                used[i]=true;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(),true);
        dfs(nums);
        return ans;
    }
};
```

### ×78.子集（组合index+size可不满）

```c++
class Solution {
public:
    vector<vector<int>>ans;
    vector<int> path;
    void dfs(const vector<int>& nums, int index){
        ans.push_back(path);

        for(int i=index; i<nums.size();i++){
            path.push_back(nums[i]);
            dfs(nums,i+1);//这里不是index是i
            path.pop_back();
        }
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(nums,0);
        return ans;
    }
};
```

### √17.电话号码的字母组合（a3×b4×c5类型，同样index）

```c++
class Solution {
public:
    unordered_map<char, string> phoneMap{
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
    };
    vector<string> ans;
    string path;
    void dfs(string digits, int index){
        if(path.size()==digits.size()){
            ans.push_back(path);
            return ;
        }
        
        for(auto c: phoneMap[digits[index]]){
            path.push_back(c);
            dfs(digits, index+1);
            path.pop_back();
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {
        dfs(digits,0);
        return ans;
    }
};
```

### √39.组合总和（完全背包版的组合，也是需要index，只是不+1，+1则0-1背包）


```c++
class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    int sum=0;
    void dfs(const vector<int>& candidates, int target,int index){
        if(sum>target){
            return ;
        }
        if(sum==target){
            ans.push_back(path);
        }
        for(int i=index;i<candidates.size();i++){
            path.push_back(candidates[i]);
            sum+=candidates[i];
            dfs(candidates,target,i);
            sum-=candidates[i];
            path.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0);
        return ans;
    }
};
```

### √22.括号生成（组合，index）

考虑清楚什么时候进入下一次dfs即可

```c++
class Solution {
public:
    string path;
    vector<string>ans;
    int Right=0;
    int Left=0;
    void dfs(int n,int index){
        if(n*2==index){
            ans.push_back(path);
            return;
        }

        if(Left<n){
            Left++;
            path.push_back('(');
            dfs(n,index+1);
            path.pop_back();
            Left--;
        }
        if(Right<Left){
            Right++;
            path.push_back(')');
            dfs(n,index+1);
            path.pop_back();
            Right--;
        }
        return;
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,0);
        return ans;
    }
};
```

### ×79.单词搜索 （往4个方向dfs，别的其实一样）
```c++
class Solution {
public:
    int m,n;
    bool dfs(vector<vector<char>>& board, string word,int i,int j,int index){
        if(i<0 || i>=m || j<0 || j>=n|| board[i][j]!=word[index])
            return false;
        if(index== word.size()-1){
            return true;
        }
        board[i][j] = '\0';
        bool ans = dfs(board,word,i+1,j,index+1)||dfs(board,word,i-1,j,index+1)||dfs(board,word,i,j+1,index+1)||dfs(board,word,i,j-1,index+1);
        board[i][j]= word[index];
        return ans;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size(), n=board[0].size();
        int ans=false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=dfs(board,word,i,j,0);
            }
        }
        return ans;
    }
};
```

### √131.分割回文串（主要是s.substr(i,j-i+1)的用法）
```c++
class Solution {
public:

    bool IsPal(string s){
        int left=0,right=s.size()-1;
        while(left<s.size() && left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    vector<string> path;
    vector<vector<string>> ans;
    void dfs(string s, int index){
        if(index==s.size()){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.size();i++){
            if(IsPal(s.substr(index,i-index+1)))
            {
                path.push_back(s.substr(index,i-index+1));
                dfs(s,i+1);
                path.pop_back();
            }
        }
        return;
    }
    vector<vector<string>> partition(string s) {
        dfs(s,0);
        return ans;
    }
};
```

### 51.N皇后（NEED）需要三个used数组，string(num, 'c')的用法
左斜线，右斜线，上下线各有一个bool vector来装
```c++
class Solution {
public:
    vector<vector<string>> ans;
    vector<int> path;
    vector<bool> used, diag1,diag2;
    
    void dfs(int n, int index){//index ctrl |
        if(path.size()==n){
            vector<string> pathS;
            for(auto p :path){
                string tmpS = string(p,'.') + 'Q'+string(n-p-1,'.');
                pathS.push_back(tmpS);
            }
            ans.push_back(pathS);
            return;
        }

        for(int i=0;i<n;i++){
            if(used[i] && diag1[i+index] && diag2[i-index+n]){
                path.push_back(i);
                used[i]=false;
                diag1[i+index]=false;
                diag2[i-index+n]=false;
                dfs(n,index+1);
                path.pop_back();
                used[i]=true;
                diag1[i+index]=true;
                diag2[i-index+n]=true;
            }
        }
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        used.assign(n,true);
        diag1.assign(2*n+1,true);
        diag2.assign(2*n+1,true);
        dfs(n,0);
        return ans;
    }
};
```
## 图论（/4）

### 200.岛屿数量

```c++
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid, int m ,int n){
        if(i<0||i>=m||j < 0 || j >= n || grid[i][j] != '1')
            return;
        
        grid[i][j] = '2'; // 插旗
        dfs(i, j - 1,grid,m,n); // 往左走
        dfs(i, j + 1,grid,m,n); // 往右走
        dfs(i - 1, j,grid,m,n); // 往上走
        dfs(i + 1, j,grid,m,n); // 往下走
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') { // 找到了一个新的岛
                    dfs(i, j,grid,m,n); // 把这个岛插满旗子，这样后面遍历到的 '1' 一定是新的岛
                    ans++;
                }
            }
        }
        return ans;
    }
};
```

### 994.腐烂的橘子（move语义来交接下一次腐烂的橘子）

```c++
class Solution {
public:
    int DIRECTIONS[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int fresh = 0;
        vector<pair<int, int>> q;

        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(grid[i][j]==1){
                    fresh++;
                }else if (grid[i][j]==2){
                    q.push_back({i,j});
                }
            }
        }

        int ans=0;
        while(fresh&& !q.empty()){
            ans++;
            vector<pair<int,int>> nxt;
            for(auto & [x,y]: q){
                for(auto d: DIRECTIONS){
                    auto i=x+d[0];
                    auto j=y+d[1];
                    if(0 <= i && i < m && 0 <= j && j < n && grid[i][j] == 1){
                        fresh--;
                        grid[i][j]=2;
                        nxt.push_back({i,j});
                    }
                }
            }
            q=move(nxt);//新增腐烂橘子是下一轮循环的重点
        }
        if(fresh==0)
            return ans;
        else 
            return -1;
    }
};
```
### ×207.课程表(NEED)

```c++
colors[i]==0 && dfs(i)

if(colors[y]==0 && dfs(y))
    return true;
//这两段比较麻烦

```


```c++
class Solution {
public:
    vector<int> colors;
    vector<vector<int>> g;
    bool dfs(int x){
        colors[x]=1;
        for(int y: g[x]){
            if(colors[y]==1)
                return true;
            if(colors[y]==0 && dfs(y))
                return true;
        }
        colors[x]=2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        g.resize(numCourses);
        colors.assign(numCourses,0);
        for(auto p : prerequisites)
            g[p[1]].push_back(p[0]);//先完成p1才能上p0

        for(int i=0;i<numCourses;i++){
            if(colors[i]==0 && dfs(i))//0时才开始dfs
                return false;
        }
        return true;
    }
};
```

### 208. 实现前缀树（结构题NEED）
node的结构体比较重要
```c++
struct Node{
    Node *child[26]{nullptr};
    bool end=false;
};
```

```c++
struct Node{
    Node *child[26]{nullptr};
    bool end=false;
};

class Trie {
public:
    Node* root= new Node();
    
    int find(const string& word){
        Node *tmp=root;
        for( auto c: word){
            if(tmp->child[c-'a']==nullptr)
                return 0;
            tmp=tmp->child[c-'a'];
        }
        if(tmp->end)
            return 1;
        else 
            return 2;
    }
    
    void insert(string word) {
        Node *tmp=root;
        for(auto c:word){
            if(tmp->child[c-'a']==nullptr){
                tmp->child[c-'a']= new Node();
            }
            tmp=tmp->child[c-'a'];
        }
        tmp->end=true;
    }
    
    bool search(string word) {
        if(find(word)==1)
            return true;
        else 
            return false;
    }
    
    bool startsWith(string prefix) {
        if(find(prefix)>0)
            return true;
        else 
            return false;
    }
};


```