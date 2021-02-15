#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &c)
    {
        int n = c.size();
        // make two variables for start and finish time
        int start = c[0][0], finish = c[0][0] + c[0][1];
        // keep a track of the waiting time
        double wait = finish - start;
        for (int i = 1; i < n; i++)
        {
            start = c[i][0];
            // if finish time is greater than arrival time, add waiting time to finish time
            if (finish > c[i][0])
            {
                finish += c[i][1];
            }
            else
            {
                // else add the order completion time to start time instead
                finish = start + c[i][1];
            }
            wait += finish - start;
        }
        return wait / n;
    }
};

void printVecVec(vector<vector<int>> &customers)
{
    for (vector<int> cust : customers)
    {
        cout << "{ ";
        for (int c : cust)
        {
            cout << c << " ";
        }
        cout << "}";
    }
    cout << endl;
}

int main()
{
    Solution mySol;
    vector<vector<int>> customers = {{1, 2}, {2, 5}, {4, 3}};
    cout << "The average waiting time for the customers: ";
    printVecVec(customers);
    cout << "is " << mySol.averageWaitingTime(customers) << endl;
    return 0;
}