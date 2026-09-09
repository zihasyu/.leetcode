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
## 双指针

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


### 238.除自身以外的乘积（前缀乘后缀）