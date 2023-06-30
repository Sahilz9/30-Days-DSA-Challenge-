#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
    vector<shared_ptr<TrieNode>> children;
    bool isWord = false;
    TrieNode() : children(26) {}
};

class Trie
{
public:
    void insert(const string &word)
    {
        shared_ptr<TrieNode> node = root;
        for (const char c : word)
        {
            const int i = c - 'a';
            if (node->children[i] == nullptr)
                node->children[i] = make_shared<TrieNode>();
            node = node->children[i];
        }
        node->isWord = true;
    }

    bool search(const string &word)
    {
        shared_ptr<TrieNode> node = find(word);
        return node && node->isWord;
    }

    bool startsWith(const string &prefix)
    {
        return find(prefix) != nullptr;
    }

private:
    shared_ptr<TrieNode> root = make_shared<TrieNode>();

    shared_ptr<TrieNode> find(const string &prefix)
    {
        shared_ptr<TrieNode> node = root;
        for (const char c : prefix)
        {
            const int i = c - 'a';
            if (node->children[i] == nullptr)
                return nullptr;
            node = node->children[i];
        }
        return node;
    }
};

int main()
{
    Trie trie;

    cout << "Enter the number of words to insert: ";
    int n;
    cin >> n;

    cin.ignore(); // Ignore newline character after reading n

    cout << "Enter the words to insert:" << endl;
    for (int i = 0; i < n; ++i)
    {
        string word;
        getline(cin, word);
        trie.insert(word);
    }

    cout << "Enter the word to search: ";
    string searchWord;
    getline(cin, searchWord);
    bool found = trie.search(searchWord);
    if (found)
        cout << "Word found!" << endl;
    else
        cout << "Word not found." << endl;

    cout << "Enter the prefix to search: ";
    string prefix;
    getline(cin, prefix);
    bool startsWithPrefix = trie.startsWith(prefix);
    if (startsWithPrefix)
        cout << "There are words with the given prefix." << endl;
    else
        cout << "No words found with the given prefix." << endl;
}

//Time Complexity: O(L) for insertion, search, and prefix search, where L is the length of the word or prefix.
//Space Complexity: O(N), where N is the total number of characters in the inserted words

// Companies:- Google, Adobe, Amazon, Salesforce,