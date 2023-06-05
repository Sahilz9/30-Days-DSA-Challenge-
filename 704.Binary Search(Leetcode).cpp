#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = start + (end - start) / 2;
        while (start <= end) {
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return -1;
    }
};

int main() {
    int n;
    cout << "Enter the size of the vector: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cout << "Enter the target value: ";
    cin >> target;

    Solution solution;

    // Call the search function and print the result
    int result = solution.search(nums, target);
    cout << "Result: " << result << endl;
}

//Link of the Question:- https://leetcode.com/problems/binary-search/description/

// Time Complexity:
// The time complexity of the binary search algorithm is O(log n), where n is the size of the input vector `nums`. 
//This is because with each iteration of the while loop, the search range is divided in half. 
//Therefore, the number of iterations required to find the target value is proportional to the logarithm of the input size.

// Space Complexity:
// The space complexity of the program is O(1) because it uses a constant amount of extra space. 
//The variables `start`, `end`, and `mid` are used to keep track of indices, and they occupy a constant amount of space. 
//The input vector `nums` does not require additional space as it is passed by reference. 
//The program does not use any dynamically allocated memory or additional data structures that grow with the input size.

//Question asked in:- Google, Adobe, Amazon, Salesforce