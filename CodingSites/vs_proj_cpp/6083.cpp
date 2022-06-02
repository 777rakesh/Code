#if 0
#include <string>
#include <iostream>

using namespace std;




class Solution {
public:
    bool digitCount(string num) {

        int count[10];



        int n = num.length();

        for (int i = 0; i < 10; i++)
        {
            count[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            int number = num[i] - '0';

            count[number]++;

        }

        for (int i = 0; i < n; i++)
        {
            if (count[i] != (num[i] - '0'))
            {
                return false;
            }
        }
        
        return true;
    }
};


int main()
{
    Solution s;
    cout << s.digitCount("1210") << "\n";
    cout << s.digitCount("030") << "\n";

    return 0;
}
#endif