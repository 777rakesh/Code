#if 0
#include <algorithm> 
#include <string>
#include <chrono>
#include <iostream>

using namespace std;

using namespace std::chrono;

class ABBADiv1
{
public:
    string canObtain(string initial, string target);
};

/*string ABBADiv1::canObtain(string initial, string target)
{
    //Termination conditions
    if (initial == target)
    {
        return "Possible";
    }

    if (initial.length() > target.length())
    {
        return "Impossible";
    }

    //Move1
    string result = canObtain(initial + "A", target);

    //Move2
    if (result != "Possible")
    {
        string move2 = initial + "B";
        reverse(move2.begin(), move2.end());
        result = canObtain(move2, target);
    }

    return result;
}*/

string ABBADiv1::canObtain(string initial, string target)
{
    if (initial.size() == target.size())
    {
        if (initial == target)
        {
            return "Possible";
        }
        else
        {
            return "Impossible";
        }
    }

    string result = "Impossible";
    char lastchar = target[target.size() - 1];
    if (lastchar == 'A')
    {
        //Move A
        //Remove character A and recurse
        result = canObtain(initial, target.substr(0 , target.size() - 1));

        if (result == "Possible")
        {
            return result;
        }
    }


    //Move B
    if (target[0] == 'B')
    {
        //If first character is B , then reverse the string and remove the B at the last character
        reverse(target.begin(), target.end());
        result = canObtain(initial, target.substr(0, target.size() - 1));
    }

    return result;
}


int main()
{
    auto start = high_resolution_clock::now();

    ABBADiv1 a;
    cout << a.canObtain("AAABBAABB", "BAABAAABAABAABBBAAAAAABBAABBBBBBBABB") <<endl;
    
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << duration.count() << endl;

}
#endif