/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
class LRUCache
{
public:
    // 双向链表节点
    struct Node
    {
        int key, value;
        Node *prev;
        Node *next;
        Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
    };

    int cap;
    unordered_map<int, Node *> cache;
    Node *head;
    Node *tail;

    LRUCache(int capacity) : cap(capacity)
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (!cache.count(key))
            return -1;
        Node *node = cache[key];
        remove(node);
        insertToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (cache.count(key))
        {
            Node *node = cache[key];
            node->value = value;
            remove(node);
            insertToHead(node);
        }
        else
        {
            if (cache.size() == cap)
            {
                Node *node = tail->prev;
                remove(node);
                cache.erase(node->key);
                delete node;
            }
            Node *node = new Node(key, value);
            cache[key] = node;
            insertToHead(node);
        }
    }

    // 移除节点
    void remove(Node *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 插入到头部
    void insertToHead(Node *node)
    {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    ~LRUCache()
    {
        Node *cur = head;
        while (cur)
        {
            Node *next = cur->next;
            delete cur;
            cur = next;
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
