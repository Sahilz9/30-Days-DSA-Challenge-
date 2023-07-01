#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int val) : val(val), next(nullptr) {}
};

class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        auto compare = [](ListNode *a, ListNode *b)
        { return a->val > b->val; };
        priority_queue<ListNode *, vector<ListNode *>, decltype(compare)> minHeap(
            compare);

        for (ListNode *list : lists)
            if (list != nullptr)
                minHeap.push(list);

        while (!minHeap.empty())
        {
            ListNode *minNode = minHeap.top();
            minHeap.pop();
            if (minNode->next)
                minHeap.push(minNode->next);
            curr->next = minNode;
            curr = curr->next;
        }

        return dummy.next;
    }
};

int main()
{
    Solution solution;
    // Example input: Merge lists [1->4->5, 1->3->4, 2->6]
    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode *> lists = {list1, list2, list3};

    ListNode *mergedList = solution.mergeKLists(lists);

    cout << "Merged List: ";
    while (mergedList != nullptr)
    {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

    // Clean up memory
    for (ListNode *list : lists)
    {
        while (list != nullptr)
        {
            ListNode *temp = list;
            list = list->next;
            delete temp;
        }
    }
}

// Time:- O(n log k)
// Space:- O(k)

// Question:- Google, Amazon, Salesforce, Paypal, Microsoft, Facebook, Adobe