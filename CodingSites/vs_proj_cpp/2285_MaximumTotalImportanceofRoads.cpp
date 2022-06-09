#if 0
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

long long count1[100000];

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {

#define maxroad (100000)

        
        memset(count1, 0, sizeof(long long) * maxroad);

        for (auto& r : roads)
        {
            count1[r[0]]++;
            count1[r[1]]++;
        }

        sort(count1, count1 + n); 

        long long tot = 0;
        for (int i = 0; i < n; i++)
        {
            tot += count1[i] * (i + 1);
        }

        return tot;
    }
};


int main()
{
    Solution s;

    vector<vector<int>> roads = { {0, 1},{1, 2},{2, 3},{0, 2},{1, 3},{2, 4} };
       
    int n = 5;

    s.maximumImportance(n, roads);
}
#endif