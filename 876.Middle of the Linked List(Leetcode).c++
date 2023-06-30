#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// Helper function to build a linked list from user input
ListNode *buildList()
{
    int val;
    cout << "Enter node value (or -1 to end): ";
    cin >> val;

    if (val == -1)
        return nullptr;

    ListNode *node = new ListNode(val);
    node->next = buildList();
    return node;
}

// Helper function to print the linked list
void printList(ListNode *head)
{
    ListNode *current = head;
    while (current)
    {
        cout << current->val << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main()
{
    ListNode *head = buildList();

    Solution solution;
    ListNode *middleNode = solution.middleNode(head);

    cout << "Middle Node: " << middleNode->val << endl;
}


//Time:- O(n)
//Space:- O(1)

//Companies:- Google, Amazon, Microsoft, Paypal 