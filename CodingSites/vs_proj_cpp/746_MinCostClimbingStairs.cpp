#if 0
#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+1);

        if (n == 1)
        {
            return cost[0];
        }

        dp[0] = cost[0];
        dp[1] = cost[1];

        for (int f = 2; f <= n; f++)
        {
            dp[f] = min(dp[f - 1], dp[f - 2]);

            if (f < n)
            {
                dp[f] += cost[f];
            }
        }

        return dp[n];
    }
};

/*
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
*/
int main()
{
    //vector<int> cost =  {10, 15, 20};
    vector<int> cost =  {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    Solution s;
    cout << s.minCostClimbingStairs(cost) << "\n";

    return 0;
}
#endif