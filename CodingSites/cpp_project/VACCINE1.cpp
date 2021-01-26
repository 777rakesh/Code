#include <iostream>
using namespace std;

int main()
{
    int d1, d2, v1 , v2, p;

    cin >> d1 >> v1 >> d2 >> v2 >> p;

    int tilldate = 0;
    int day;
    for (day = 1; day <=1000; day++)
    {
        if(d1<=day)
        {
            tilldate += v1;
        }
        if(d2<= day)
        {
            tilldate += v2;
        }

        if(tilldate >= p)
        {
            break;
        }

    }
    
    cout << day;


    return 0;
}