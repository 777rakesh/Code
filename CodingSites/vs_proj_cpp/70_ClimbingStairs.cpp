
#if 0
#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(47);

        if (n == 1)
        {
            return 1;
        }

        dp[n] = 1;
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1] + dp[i + 2];
        }

        return dp[0];
    }
};

int main()
{
    Solution s;
    cout << s.climbStairs(1)<<"\n";

    cout << s.climbStairs(2) << "\n";

    cout << s.climbStairs(3) << "\n";

    cout << s.climbStairs(10) << "\n";

    return 0;
}
#endif