#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;


class Solution {
public:
    map<long long, long long> count;

    long long findNth(long long N)
    {
        // code here.
        long long bak = N;

        string convnum = "";

        long long rem;
        long long quot;
        do
        {
            quot = N / 9;
            rem = N % 9;

            N = quot;

            convnum = convnum + to_string(rem);

        } while (quot);

        reverse(convnum.begin(), convnum.end());

        long long num = atoll(convnum.c_str());

        return num;
    }
};





int main()
{
    Solution s;
    cout << s.findNth(100);

    return 0;
}