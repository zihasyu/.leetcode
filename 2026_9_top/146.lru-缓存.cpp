/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */
#include <bits/stdc++.h>
using namespace std;
// @lc code=start
class LRUCache
{
private:
    int _capacity = 0;
    list<pair<int, int>> LruCache;
    unordered_map<int, list<pair<int, int>>::iterator> Map;

public:
    LRUCache(int capacity)
    {
        _capacity = capacity;
    }

    int get(int key)
    {
        auto it = Map.find(key);
        if (it == Map.end())
        {
            return -1;
        }
        else
        {
            int value = it->second->second;
            LruCache.erase(it->second);
            LruCache.push_front({key, value});
            Map[key] = LruCache.begin();
            return value;
        }
    }

    void put(int key, int value)
    {
        auto it = Map.find(key);
        if (it != Map.end())
        {
            LruCache.erase(it->second);
        }
        LruCache.push_front({key, value});
        Map[key] = LruCache.begin();
        if (Map.size() > _capacity)
        {
            Map.erase(LruCache.back().first);
            LruCache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
