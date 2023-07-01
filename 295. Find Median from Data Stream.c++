#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
            maxHeap.push(num);
        else
            minHeap.push(num);

        // Balance two heaps s.t.
        // |maxHeap| >= |minHeap| and |maxHeap| - |minHeap| <= 1
        if (maxHeap.size() < minHeap.size())
            maxHeap.push(minHeap.top()), minHeap.pop();
        else if (maxHeap.size() - minHeap.size() > 1)
            minHeap.push(maxHeap.top()), maxHeap.pop();
    }

    double findMedian()
    {
        if (maxHeap.size() == minHeap.size())
            return (maxHeap.top() + minHeap.top()) / 2.0;
        return maxHeap.top();
    }

private:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<>> minHeap;
};

int main()
{
    MedianFinder finder;

    // Add numbers
    finder.addNum(1);
    finder.addNum(2);
    finder.addNum(3);
    finder.addNum(4);

    // Find median
    double median = finder.findMedian();
    cout << "Median: " << median << endl;
}

// Time:- O(n log n)
// Space:- O(n)

// Question:- Google, Amazon, Salesforce, Paypal