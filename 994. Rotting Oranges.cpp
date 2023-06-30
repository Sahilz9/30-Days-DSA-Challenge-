#include <bits/stdc++.h>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
  }
};

int main() {
  int m, n;
  cout << "Enter the number of rows and columns: ";
  cin >> m >> n;

  vector<vector<int>> grid(m, vector<int>(n));
  cout << "Enter the grid elements (0 - empty, 1 - fresh orange, 2 - rotten orange):" << endl;
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> grid[i][j];
    }
  }

  Solution solution;
  int result = solution.orangesRotting(grid);
  cout << "Minimum time required for all oranges to rot: " << result << endl;

  return 0;
}


//Time:- O(kmn)
//Space:- O(mn)

//Companies:- Google, Amazon, Paypal, Microsoft