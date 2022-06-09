#if 0
#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
public:
    int fib(int n) {
        if (n == 0)
        {
            //cout << n;
            return n;
        }
        else if (n == 1)
        {
            //cout << n;
            return n;
        }
        else
        {
            int fibv = ( fib(n - 2) + fib(n - 1) );
            //cout << fibv;
            return fibv;
        }
    }
};*/

class Solution {
public:
    int fib(int n) {
        vector<int> dp(n + 2);
        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.fib(5);

    return 0;
}

#endif