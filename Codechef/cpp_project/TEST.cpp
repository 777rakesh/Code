#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector <int> result;

    int temp;
    while (true)
    {
        cin >> temp;
        if(temp == 42)
        {
            break;
        }        
        cout<<temp<<endl;
    }

    return 0;
}