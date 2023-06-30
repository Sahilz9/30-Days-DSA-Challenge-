#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        const int m = grid.size();
        const int n = grid[0].size();
        const vector<int> dirs{0, 1, 0, -1, 0};
        int ans = 0;

        auto bfs = [&](int r, int c)
        {
            queue<pair<int, int>> q{{{r, c}}};
            grid[r][c] = '2'; // Mark '2' as visited
            while (!q.empty())
            {
                const auto [i, j] = q.front();
                q.pop();
                for (int k = 0; k < 4; ++k)
                {
                    const int x = i + dirs[k];
                    const int y = j + dirs[k + 1];
                    if (x < 0 || x == m || y < 0 || y == n)
                        continue;
                    if (grid[x][y] != '1')
                        continue;
                    q.emplace(x, y);
                    grid[x][y] = '2'; // Mark '2' as visited
                }
            }
        };

        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (grid[i][j] == '1')
                {
                    bfs(i, j);
                    ++ans;
                }

        return ans;
    }
};

vector<vector<char>> createGrid(int m, int n)
{
    vector<vector<char>> grid(m, vector<char>(n));
    cout << "Enter the grid elements ('1' for land, '0' for water):" << endl;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            cin >> grid[i][j];
    return grid;
}

int main()
{
    Solution solution;

    cout << "Enter the number of rows in the grid: ";
    int m;
    cin >> m;

    cout << "Enter the number of columns in the grid: ";
    int n;
    cin >> n;

    vector<vector<char>> grid = createGrid(m, n);

    int numIslands = solution.numIslands(grid);
    cout << "The number of islands in the grid is: " << numIslands << endl;
}

// Time:- O(mn)
// Space:- O(min(m,n))

// Companies:- Amazon, Salesforce, Paypal, Facebook