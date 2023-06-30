#include <bits/stdc++.h>
using namespace std;

struct T
{
    string value;
    int timestamp;
    T(string value, int timestamp) : value(value), timestamp(timestamp) {}
};

class TimeMap
{
public:
    void set(string key, string value, int timestamp)
    {
        map[key].emplace_back(value, timestamp);
    }

    string get(string key, int timestamp)
    {
        if (!map.count(key))
            return "";

        const vector<T> &A = map[key];
        int l = 0;
        int r = A.size();

        while (l < r)
        {
            const int m = (l + r) / 2;
            if (A[m].timestamp > timestamp)
                r = m;
            else
                l = m + 1;
        }

        return l == 0 ? "" : A[l - 1].value;
    }

private:
    unordered_map<string, vector<T>> map;
};

int main()
{
    TimeMap timeMap;

    // Perform set operations
    timeMap.set("key1", "value1", 1);
    timeMap.set("key1", "value2", 3);
    timeMap.set("key2", "value3", 5);

    // Perform get operations
    cout << timeMap.get("key1", 2) << endl; // Output: value1
    cout << timeMap.get("key1", 4) << endl; // Output: value2
    cout << timeMap.get("key1", 6) << endl; // Output: value2
    cout << timeMap.get("key2", 5) << endl; // Output: value3
    cout << timeMap.get("key3", 1) << endl; // Output: ""
}


// Time: Constructor: O(1), set(key: str, value: str, timestamp: int):O(1), get(key: str, timestamp: int): O(log n), where n=∣map[key]∣
// Space: O(∣set(key:str, value: str, timestamp: int)∣)

//Companies:- Google, Adobe, Amazon, Facebook