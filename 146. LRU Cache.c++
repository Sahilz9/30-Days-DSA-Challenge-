#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    int value;
    shared_ptr<Node> prev;
    shared_ptr<Node> next;
    Node(int key, int value) : key(key), value(value) {}
};

class LRUCache
{
public:
    LRUCache(int capacity) : capacity(capacity)
    {
        join(head, tail);
    }

    int get(int key)
    {
        const auto it = keyToNode.find(key);
        if (it == keyToNode.cend())
            return -1;

        shared_ptr<Node> node = it->second;
        remove(node);
        moveToHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (const auto it = keyToNode.find(key); it != keyToNode.cend())
        {
            shared_ptr<Node> node = it->second;
            node->value = value;
            remove(node);
            moveToHead(node);
            return;
        }

        if (keyToNode.size() == capacity)
        {
            shared_ptr<Node> lastNode = tail->prev;
            keyToNode.erase(lastNode->key);
            remove(lastNode);
        }

        moveToHead(make_shared<Node>(key, value));
        keyToNode[key] = head->next;
    }

private:
    const int capacity;
    unordered_map<int, shared_ptr<Node>> keyToNode;
    shared_ptr<Node> head = make_shared<Node>(-1, -1);
    shared_ptr<Node> tail = make_shared<Node>(-1, -1);

    void join(shared_ptr<Node> node1, shared_ptr<Node> node2)
    {
        node1->next = node2;
        node2->prev = node1;
    }

    void moveToHead(shared_ptr<Node> node)
    {
        join(node, head->next);
        join(head, node);
    }

    void remove(shared_ptr<Node> node)
    {
        join(node->prev, node->next);
    }
};

int main()
{
    int capacity;
    cout << "Enter the capacity of the LRUCache: ";
    cin >> capacity;

    LRUCache cache(capacity);

    int numQueries;
    cout << "Enter the number of queries: ";
    cin >> numQueries;

    for (int i = 0; i < numQueries; ++i)
    {
        int queryType;
        cout << "Enter the query type (1 for get, 2 for put): ";
        cin >> queryType;

        if (queryType == 1)
        {
            int key;
            cout << "Enter the key: ";
            cin >> key;
            int value = cache.get(key);
            cout << "Value: " << value << endl;
        }
        else if (queryType == 2)
        {
            int key, value;
            cout << "Enter the key and value: ";
            cin >> key >> value;
            cache.put(key, value);
        }
        else
        {
            cout << "Invalid query type." << endl;
        }
    }
}

// Time:- get(key: int), put(key: int, value: int):O(1)
// Space:- O(capacity)

// Question:- Amazon,  Microsoft, Facebook, Adobe