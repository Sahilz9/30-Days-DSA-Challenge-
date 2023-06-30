#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>

using namespace std;

class UnionFind
{
public:
    UnionFind(int n) : id(n), sz(n, 1)
    {
        iota(id.begin(), id.end(), 0);
    }

    void unionBySize(int u, int v)
    {
        const int i = find(u);
        const int j = find(v);
        if (i == j)
            return;
        if (sz[i] < sz[j])
        {
            sz[j] += sz[i];
            id[i] = j;
        }
        else
        {
            sz[i] += sz[j];
            id[j] = i;
        }
    }

    int find(int u)
    {
        return id[u] == u ? u : id[u] = find(id[u]);
    }

private:
    vector<int> id;
    vector<int> sz;
};

class Solution
{
public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts)
    {
        vector<vector<string>> ans;
        unordered_map<string, int> emailToIndex;       // {email: index}
        unordered_map<int, set<string>> indexToEmails; // {index: {emails}}
        UnionFind uf(accounts.size());

        for (int i = 0; i < accounts.size(); ++i)
        {
            const string name = accounts[i][0];
            for (int j = 1; j < accounts[i].size(); ++j)
            {
                const string email = accounts[i][j];
                const auto it = emailToIndex.find(email);
                if (it == emailToIndex.end())
                {
                    // Only record if it's the first time we see thie email
                    emailToIndex[email] = i;
                }
                else
                {
                    // Otherwise, union i w/ emailToIndex[index]
                    uf.unionBySize(i, it->second);
                }
            }
        }

        for (const auto &[email, index] : emailToIndex)
            indexToEmails[uf.find(index)].insert(email);

        for (const auto &[index, emails] : indexToEmails)
        {
            const string name = accounts[index][0];
            vector<string> row{name};
            row.insert(row.end(), emails.begin(), emails.end());
            ans.push_back(row);
        }

        return ans;
    }
};

int main()
{
    Solution solution;

    // Provide input
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}};

    // Perform accounts merge
    vector<vector<string>> mergedAccounts = solution.accountsMerge(accounts);

    // Print the merged accounts
    for (const auto &account : mergedAccounts)
    {
        for (const string &email : account)
        {
            cout << email << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time:- O(nk log nk + nkα(n)) == O(nk log nk), where k = max(|accounts[i]|)
// Space:- O(n+nk) = O(nk)

// Companies:- Adobe, Amazon, Facebook, Microsoft