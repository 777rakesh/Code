#if 0
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool strongPasswordCheckerII(string password) {

        bool lowc = false;
        bool upc = false;
        bool digit = false;

        bool spec = false;        
        string special = "!@#$%^&*()-+";

        bool cont = false;

        int len = password.length();

        if (len < 8)
        {
            return false;
        }

        for (int l = 0; l < len; l++)
        {
            if ( (char)password[l] >= 'a' && (char)password[l] <= 'z')
            {
                lowc = true;
            }
            else if ((char)password[l] >= 'A' && (char)password[l] <= 'Z')
            {
                upc = true;
            }
            else if ((char)password[l] >= '0' && (char)password[l] <= '9')
            {
                digit = true;
            }
            else if ( special.find(password[l]) != string::npos)
            {
                spec = true;
            }

            if (l != 0)
            {
                if (password[l] == password[l - 1])
                {
                    cont = true;
                    break;
                }
            }
        }


        if (cont)
        {
            return false;
        }
        if (lowc && upc && digit && spec)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Solution s;

    //string test = "IloveLe3tcode!";
    //string test = "Me+You--IsMyDream";
    string test = "1aB!";

    cout << s.strongPasswordCheckerII(test);
    return 0;
}
#endif