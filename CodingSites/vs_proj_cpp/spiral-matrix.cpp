#if 0
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        bool isVisited[10][10];
        memset(isVisited, false, sizeof(bool) * 10 * 10);

        vector<int> nodesVisited;

        int size = m * n;

        int curm = 0;
        int curn = 0;

        int totVisited = 0;

        bool curvisited = false;

        do {
            // Traverse right
            while ((curm < m) && (isVisited[curm][curn] == false)) {
                isVisited[curm][curn] = true;

                nodesVisited.push_back(matrix[curn][curm]);

                curm++;
                totVisited++;

                curvisited = true;
            }
            if (curvisited)
            {
                curvisited = false;
                curm--;
                curn++;
            }

            // Traverse downwards
            while (curn < n && (isVisited[curm][curn] == false)) {
                isVisited[curm][curn] = true;

                nodesVisited.push_back(matrix[curn][curm]);

                curn++;
                totVisited++;
                curvisited = true;
            }
            if (curvisited)
            {
                curvisited = false;
                curn--;
                curm--;
            }

            // Traverse left
            while (curm >= 0 && (isVisited[curm][curn] == false)) {
                isVisited[curm][curn] = true;

                nodesVisited.push_back(matrix[curn][curm]);

                curvisited = true;
                totVisited++;

                curm--;
            }
            if (curvisited)
            {
                curm++;
                curn--;
                curvisited = false;
            }

            // Traverse top
            while (curn >= 0 && (isVisited[curm][curn] == false)) {
                isVisited[curm][curn] = true;

                nodesVisited.push_back(matrix[curn][curm]);

                totVisited++;
                curvisited = true;
                
                curn--;
            }
            if (curvisited)
            {
                curn++;
                curm++;
                curvisited = false;
            }

            // Stop if total number of nodes visited is equal to size
        } while (totVisited < size);

        return nodesVisited;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> input = //{ {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    { {1, 2, 3, 4}, { 5,6,7,8 }, { 9,10,11,12 }};

    s.spiralOrder(input);

    return 0;
}
#endif