#include <iostream>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

int main()
{
	int t;
	cin >> t;

	vector<string> inputs;

	for (int loop = 0; loop < t; loop++)
	{
		string input;
		cin >> input;
		inputs.push_back(input);
	}

	vector<string>::iterator it;
	for (it = inputs.begin(); it != inputs.end(); it++)
	{
		string curr = *it;

		map<char, unsigned int> occurencehalf1;
		map<char, unsigned int> occurencehalf2;

		int size = curr.size();
		int mid = size/2;

		bool even = (size % 2 == 0) ? true : false;

		int secondhalfoff = 0;
		if(even)
		{
			secondhalfoff = mid;
		}
		else
		{
			secondhalfoff = mid+1;
		}

		string half1 = curr.substr(0, mid);
		string half2 = curr.substr(secondhalfoff, curr.size());

		for (int i = 0; i < mid; i++)
		{
			char a = half1[i];
			char b = half2[i];

			unsigned int counta = 0;
			auto it1 = occurencehalf1.find(a);
			if (it1 != occurencehalf1.end())
			{
				counta = it1->second;
				occurencehalf1.erase(a);
			}
			else
			{
			}
			occurencehalf1.insert(pair<char, unsigned int>(a, counta + 1));

			unsigned int countb = 0;
			auto it2 = occurencehalf2.find(b);
			if (it2 != occurencehalf2.end())
			{
				countb = it2->second;
				occurencehalf2.erase(b);
			}
			else
			{

			}
			occurencehalf2.insert(pair<char, unsigned int>(b, countb + 1));

		}


		if( occurencehalf1  ==  occurencehalf2)
		{
			cout<< "YES"<<endl;
		}
		else
		{
			cout << "NO"<<endl;
		}
	}

	return 0;
}