#include <iostream>
#include <vector>
#include <set>
#include <time.h>

using namespace std;

class RandomizedSet
{
    set<int> RandomSet;

public:
    /** Initialize your data structure **/
    RandomizedSet()
    {
    }
    /** Inserts a value to the set. Returns true if the set did not already contain the element.**/
    bool insert(int val)
    {
        // if the value is already present in the set return false
        if (RandomSet.find(val) != RandomSet.end())
            return false;
        RandomSet.insert(val);
        return true;
    }
    /** Removes a value from the set. Returns true if the contained the specified element.**/
    bool remove(int val)
    {
        // if the value is found in the set, erase it
        if (RandomSet.find(val) != RandomSet.end())
        {
            RandomSet.erase(val);
        }
        return false;
    }
    /** Get a random element from the set**/
    int getRandom()
    {
        // get a random index from 0 to random set size
        int idx = rand() % RandomSet.size();
        // get the beginning iterator
        set<int>::iterator it = RandomSet.begin();
        // advance the iterator to the index
        advance(it, idx);
        // return the value at that iterator
        return *it;
    }
};

int main()
{
    srand(time(0));
    RandomizedSet *obj = new RandomizedSet();
    bool insert1 = obj->insert(5) ? "5 inserted" : "5 not inserted";
    bool insert2 = obj->insert(10) ? "10 inserted" : "10 not inserted";
    bool insert3 = obj->insert(15) ? "15 inserted" : "15 not inserted";
    int randNum = obj->getRandom();
    cout << "The random number selected from the set is " << randNum << endl;
}