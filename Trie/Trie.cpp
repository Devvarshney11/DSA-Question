#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *child[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
        isTerminal = false;
    }
};

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    }
    // Function for insertion in trie
    void insertUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return;
        }
        int index = word[0] - 'A';
        TrieNode *children;
        if (root->child[index] != NULL)
        {
            children = root->child[index];
        }
        else
        {
            children = new TrieNode(word[0]);
            root->child[index] = children;
        }
        insertUtil(children, word.substr(1));
    }
    void insert(string word)
    {
        insertUtil(root, word);
    }
    // Function for searching in trie
    bool searchUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            return root->isTerminal;
        }
        int index = word[0] - 'A';
        TrieNode *children = nullptr;
        if (root->child[index] != NULL)
        {
            children = root->child[index];
        }
        else
        {
            return false;
        }
        return searchUtil(children, word.substr(1));
    }
    bool search(string word)
    {
        return searchUtil(root, word);
    }
    // Function to remove word from trie
    void removeUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }
        int index = word[0] - 'A';
        TrieNode *children = nullptr;
        if (root->child[index] != NULL)
        {
            children = root->child[index];
        }
        else
        {
            return;
        }
        removeUtil(children, word.substr(1));
    }
    void removeWord(string word)
    {
        removeUtil(root,word);
    }
};
int main()
{
    Trie t;
    t.insert("ARM");
    t.insert("DO");
    t.insert("TIME");
    t.removeWord("ARM");
    cout << t.search("ARM") << endl;
    cout << t.search("D") << endl;
    cout << t.search("TIM") << endl;
    return 0;
}