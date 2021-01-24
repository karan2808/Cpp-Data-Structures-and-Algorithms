#include <iostream>
using namespace std;

// make a trie node
class TrieNode
{
    TrieNode **links;
    // 26 links for each letter
    const int R = 26;
    // is end of word?
    bool isEow = false;

public:
    // constructor
    TrieNode()
    {
        links = new TrieNode *[R];
        for (int i = 0; i < R; i++)
        {
            links[i] = NULL;
        }
    }
    // destructor
    ~TrieNode()
    {
        delete links;
    }

    // check if end of word
    bool isEnd()
    {
        return isEow;
    }
    // set as end of word
    void setEnd()
    {
        isEow = true;
    }
    void put(char c, TrieNode *node)
    {
        links[c - 'a'] = node;
    }
    // get the next node
    TrieNode *get(char c)
    {
        return links[c - 'a'];
    }
    // check if node contains key
    bool containsKey(char c)
    {
        return links[c - 'a'] != NULL;
    }
};

class Trie
{
    TrieNode *root;

public:
    // we initialize the root node
    Trie()
    {
        root = new TrieNode();
    }
    // Insert a new word into the trie
    void insert(string word)
    {
        // get current node
        TrieNode *curr = root;

        for (char c : word)
        {
            // if key not found, insert
            if (!curr->containsKey(c))
            {
                // we put a new trie node
                curr->put(c, new TrieNode());
            }
            // go to next link
            curr = curr->get(c);
        }
        curr->setEnd();
    }

    // search the prefix node
    TrieNode *searchPrefix(string word)
    {
        TrieNode *curr = root;
        for (char c : word)
        {
            if (!curr->containsKey(c))
                return NULL;
            curr = curr->get(c);
        }
        return curr;
    }

    // search for the word
    bool search(string word)
    {
        TrieNode *curr = searchPrefix(word);
        if (curr != NULL && curr->isEnd())
            return true;
        return false;
    }

    // returns if there is any word in the trie that starts with the given prefix
    bool startsWith(string prefix)
    {
        if (searchPrefix(prefix) != NULL)
            return true;
        return false;
    }
};

int main()
{
    Trie t;
    t.insert("hello world");
    cout << t.startsWith("hello") << endl;
    cout << t.startsWith("yo") << endl;
    cout << t.search("hello world") << endl;
    cout << t.search("hello ") << endl;
    return 0;
}