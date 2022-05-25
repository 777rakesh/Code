#if 0
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

vector <int> output;

int main()
{
    int temp;
    while (true)
    {
        cin >> temp;
        if (temp == 42)
        {
            break;
        }
        output.push_back(temp);
    }

    vector<int>::iterator it;

    for (it = output.begin(); it != output.end(); it++)
    {
        cout << *it << endl;
    }

    return 0;
}
#endif