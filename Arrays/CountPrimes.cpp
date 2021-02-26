#include <iostream>

using namespace std;

class Solution
{
public:
    int countPrimes(int n)
    {
        if (n < 2)
            return 0;
        // initialize a count variable
        int count = 0;
        // make a boolean array set to true
        bool *primes = new bool[n];

        for (int i = 0; i < n; i++)
        {
            primes[i] = true;
        }
        // loop through setting each composite element to false
        for (int i = 2; i * i < n; i++)
        {
            if (primes[i])
            {
                for (int j = i; j * i < n; j++)
                {
                    primes[i * j] = false;
                }
            }
        }
        // count the number of primes
        for (int i = 2; i < n; i++)
        {
            if (primes[i])
                count++;
        }
        return count;
    }
};

int main()
{
    Solution mySol;
    cout << "The number of prime numbers from 1 to 25 is " << mySol.countPrimes(25) << endl;
    return 0;
}