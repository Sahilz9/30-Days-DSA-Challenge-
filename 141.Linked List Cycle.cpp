#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;
    }
};

ListNode *createLinkedList()
{
    int n;
    cout << "Enter the number of elements in the linked list: ";
    cin >> n;

    if (n == 0)
        return NULL;

    cout << "Enter the elements of the linked list: ";
    ListNode *head = NULL;
    ListNode *tail = NULL;

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;

        ListNode *new_node = new ListNode(value);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
        }
        else
        {
            tail->next = new_node;
            tail = new_node;
        }
    }

    return head;
}

int main()
{
    ListNode *head = createLinkedList();

    Solution solution;
    bool hasCycle = solution.hasCycle(head);

    if (hasCycle)
        cout << "The linked list contains a cycle." << endl;
    else
        cout << "The linked list does not contain a cycle." << endl;
}
//Time complexity:- O(N)
//Space complexity:- O(1)

//Question asked in:- Google, Paypal, Amazon, Facebook