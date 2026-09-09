/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 *
 * list当双向链表，map<int, list<pair<int,int>>::iterator>当索引，以及完成O(1)
 */
#include <list>
#include <iostream>
#include <utility>
#include <unordered_map>
using namespace std;

// @lc code=start
class LRUCache
{
    list<pair<int, int>> Cache; // 存储键值对，最近使用的放在前面
    unordered_map<int, list<pair<int, int>>::iterator> Map;
    int _capacity;
    int curSize = 0;

public:
    LRUCache(int capacity) : _capacity(capacity)
    {
    }

    int get(int key)
    {
        auto it = Map.find(key);
        if (it != Map.end())
        {
            auto value = it->second->second;
            Cache.erase(it->second);
            Cache.push_front({key, value});
            Map[key] = Cache.begin();
            return value;
        }
        else
            return -1;
    }

    void put(int key, int value)
    {
        auto it = Map.find(key);
        if (it != Map.end())
        {
            Cache.erase(it->second);
            Cache.push_front({key, value});
            Map[key] = Cache.begin();
        }
        else
        {
            if (_capacity > curSize)
            {
                Cache.push_front({key, value});
                Map[key] = Cache.begin();
                curSize++;
            }
            else
            {
                Cache.push_front({key, value});
                Map[key] = Cache.begin();
                auto popIt = Cache.back();
                Map.erase(popIt.first);
                Cache.pop_back();
            }
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
