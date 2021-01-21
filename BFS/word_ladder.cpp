#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solve
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> wordList)
    {
        unordered_set<string> word_list;
        // make a word set for fast access
        for (string s : wordList)
        {
            word_list.insert(s);
        }
        // check if the end word is in the set
        if (word_list.find(endWord) == word_list.end())
            return 0;
        // make a queue for bfs
        queue<string> que;
        que.push(beginWord);
        int level = 1;

        // start bfs, while que has elements to visit
        while (!que.empty())
        {
            int size = que.size();
            while (size--)
            {
                string current = que.front();
                que.pop();
                for (int i = 0; i < current.size(); i++)
                {
                    string temp = current;
                    // go over all the characters and replace a char
                    for (char c = 'a'; c < 'z'; c++)
                    {
                        current[i] = c;
                        if (current == temp) continue;
                        // check if we found the end word
                        if (current == endWord)
                            return level + 1;
                        // push the modified word to the queue
                        if (word_list.find(current) != word_list.end())
                        {
                            que.push(current);
                            // erase the word from the set, we don't need to worry
                            word_list.erase(current);
                        }
                    }
                    // reset to original
                    current = temp;
                }
            }
            level++;
        }
        // else return 0
        return 0;
    }
};

int main()
{
    Solve mySol;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit";
    string endWord = "cog";
    cout << "The number of words in the shortest transformation sequence is: " << mySol.ladderLength(beginWord, endWord, wordList) << endl;
    return 0;
}