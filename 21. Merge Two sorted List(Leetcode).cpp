#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        if (list1->val > list2->val)
            swap(list1, list2);
        ListNode *res = list1;
        while (list1 != nullptr && list2 != nullptr)
        {
            ListNode *temp = nullptr;
            while (list1 != nullptr && list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            temp->next = list2;
            swap(list1, list2);
        }
        return res;
    }
};

// Helper function to create a linked list from an array
ListNode *createLinkedList(int arr[], int size)
{
    if (size == 0)
        return nullptr;

    ListNode *head = new ListNode(arr[0]);
    ListNode *curr = head;

    for (int i = 1; i < size; i++)
    {
        curr->next = new ListNode(arr[i]);
        curr = curr->next;
    }

    return head;
}

// Helper function to print the linked list
void printLinkedList(ListNode *head)
{
    ListNode *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->val << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main()
{
    // Create the input linked lists
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    ListNode *list1 = createLinkedList(arr1, size1);
    ListNode *list2 = createLinkedList(arr2, size2);

    // Merge the two lists
    Solution solution;
    ListNode *mergedList = solution.mergeTwoLists(list1, list2);

    // Print the merged list
    printLinkedList(mergedList);
}

//Time complexity can be expressed as O(m + n), where m and n are the lengths of the input lists.

//Space complexity of the given program is O(1) since it only uses a constant amount of additional space, 
//regardless of the input size. The program does not dynamically allocate any extra memory based on the input size.