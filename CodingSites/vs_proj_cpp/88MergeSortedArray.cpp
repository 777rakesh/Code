#if 0
#include <vector>
#include <iterator>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {


        vector<int> tem;

        vector<int>::iterator i = nums1.begin();
        vector<int>::iterator j = nums2.begin();
        int nums1idx = 0;

        while (nums1idx != m || j != nums2.end())
        {
            if (i == nums1.end())
            {
                tem.push_back(*j);
                j++;
            }
            else if (j == nums2.end())
            {
                tem.push_back(*i);
                i++;
                nums1idx++;
            }
            else
            {
                if (*i < *j && nums1idx < m)
                {
                    tem.push_back(*i);
                    i++;
                    nums1idx++;
                }
                else
                {
                    tem.push_back(*j);
                    j++;
                }
            }
        }

        nums1 = tem;
    }
};

int main()
{
    //vector<int> a = { 1,2,3,0,0,0 };


    //vector<int> b = { 2,5,6 };

    //vector<int> a = { 1 };
    //vector<int> b = {  };

    vector<int> a = { 0 };
    vector<int> b = { 1 };

    Solution s;
    s.merge(a, 0, b, 1);

    return 0;
}
#endif