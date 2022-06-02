#if 0
#include <unordered_map>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

//#define MAX_SENDER (10)

// Function to convert a map<key,value> to a multimap<value,key>
multimap<int, string> invert(map<string, int>& mymap)
{
    multimap<int, string> multiMap;

    map<string, int> ::iterator it;
    for (it = mymap.begin(); it != mymap.end(); it++)
    {
        multiMap.insert(make_pair(it->second, it->first));
    }

    return multiMap;

}
class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {

        map<string, int> wordcount;


        int nummsg = messages.size();
        for (int i = 0; i < nummsg; i++)
        {
            int wordc =  count(messages[i].cbegin(), messages[i].cend(), ' ') + 1;

            wordcount[senders[i]] += wordc;
        }

        //map<string, int>::iterator it = wordcount.begin();
        //map<string, int>::iterator it1 = wordcount.begin();

        multimap<int, string> newmap = invert(wordcount);

        // print the multimap
        cout << "The map, sorted by value is: " << endl;
        multimap<int, string> ::iterator iter;
        for (iter = newmap.begin(); iter != newmap.end(); iter++)
        {
            // printing the second value first because the 
            // order of (key,value) is reversed in the multimap
            cout << iter->second << ": " << iter->first << endl;
        }


        map<int, string>::iterator it = newmap.end();
        map<int, string>::iterator it1 = newmap.end();
        it--;
        it1--;

        if (wordcount.size() == 1)
        {
            return it->second;
        }
        else if (it->first == (--it1)->first)
        {
            int small = lexicographical_compare(it->second.cbegin(), it->second.cend(), it1->second.cbegin(), it1->second.cend());
            if (small)
            {
                return it1->second;
            }
            else
            {
                return it->second;
            }
        }
        else
        {
            return it->second;
        }

        //return senders[0];
    }
};

int main()
{
    Solution s;
    vector<string> messages{ "Hello userTwooo", "Hi userThree", "Wonderful day Alice", "Nice day userThree" };
    vector<string> sender{ "Alice", "userTwo", "userThree", "Alice" };
    cout << s.largestWordCount(messages, sender) << "\n";

    vector<string> messages1{"How is leetcode for everyone", "Leetcode is useful for practice"};
    vector<string> sender1{ "Bob", "Charlie" };

    cout << s.largestWordCount(messages1, sender1) << "\n";

    vector<string> messages2{ "p mmV", "Lb WE u H x f YT", "Rey", "q", "Y R", "Ng", "mP lo oA l jd y", "CP y r N wHA", "Bt l", "Y S xv MNS", "WG vz", "S pl l Dz fX D TpI", "zGq", "z S D" };
    vector<string> sender2{ "QMnVn", "QMnVn", "nkq", "o", "EEM", "QMnVn", "o", "nkq", "Gd", "Gd", "nkq", "o", "EEM", "EEM" };
    cout << s.largestWordCount(messages2, sender2) << "\n";

    return 0;
}
#endif