// { Driver Code Starts
// Initial Template for C++

//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
using namespace std;

// } Driver Code Ends


class Solution {

public:
    int find_min(int sockcount[], int numcol, int reqpairs) {
        // Your code geos here

        sort(sockcount, sockcount+numcol);

        int totalpicks = 0;
        int totalpairs = 0;

        if (numcol == 1)
        {
            if (reqpairs * 2 <= sockcount[0])
            {
                return (reqpairs * 2);
            }
            else
            {
                return -1;
            }
        }

        int col = 0;
        int totalparispossile = 0;
        for (col = 0; col < numcol; col++)
        {
            int socks = 0;

            if (col == 0)
            {
                socks = sockcount[0];
            }
            else
            {
                socks = sockcount[col] - (sockcount[col - 1] - sockcount[col - 1] % 2) ;
            }

            int remcolors = numcol - col;

            int pairpossible = socks / 2;

            int currtotpairs = pairpossible * remcolors;
            
            if ( (totalpairs + currtotpairs) >= reqpairs)
            {
                //last loop

                int pairsrem = reqpairs - totalpairs;

                int pairsofeachcolor = 0;
                int picks = 0;

                if (pairsrem >= remcolors)
                {
                    pairsofeachcolor = (pairsrem / remcolors);  // distribute to all colors

                    picks = (pairsofeachcolor * remcolors) * 2;

                    pairsrem = pairsrem - (pairsofeachcolor * remcolors);

                    int rempickablepairs = 0;

                    for (int j = col; j < numcol; j++)
                    {
                        int socrem = sockcount[j] - (pairsofeachcolor * 2);
                        if(socrem>1)
                        {
                            rempickablepairs += (socrem/2);
                        }

                        sockcount[j] = socrem - (totalparispossile * 2);
                    }

                    if(pairsrem > rempickablepairs)
                    {
                        return -1;
                    }

                    while (pairsrem)
                    {
                        for (int j = col; j < numcol; j++)
                        {
                            if (sockcount[j] > 1)
                            {
                                sockcount[j] -= 2;
                                pairsrem--;

                                picks += 2;
                            }
                        }
                    }

                    for (int j = col; j < numcol; j++)
                    {
                        if (sockcount[j] != 0)
                        {
                            picks++;
                        }
                    }

                    
                }
                else
                {
                    if (col == 0)
                    {
                        picks = remcolors + pairsrem + (pairsrem - 1);
                    }
                    else
                    {
                        picks = remcolors + pairsrem + (pairsrem);
                    }
                }

                totalpicks += picks;

                break;
            }
            
            totalparispossile += pairpossible;

            totalpicks += (socks - socks % 2) * remcolors;
            if (socks % 2)
            {
                totalpicks++;
            }
            
            totalpairs += currtotpairs;

        } //for

        if (col == numcol && totalpairs != reqpairs)
        {
            //not possible
            totalpicks = -1;
        }

        return totalpicks;
    }

};

// { Driver Code Starts.

int main() {
    int a[] = { 9, 8, 5, 5, 10, 5 };
    Solution obj;
    cout << obj.find_min(a, 6, 18) << endl;

    return 1;
}
// } Driver Code Ends