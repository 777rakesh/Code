#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        vector<int> dp(43);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
        }

        return dp[n];
    }
};

int main()
{
    Solution s;
    cout << s.tribonacci(25);

    return 0;
}