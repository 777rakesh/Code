#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main()
{
	int t;
	cin >> t;

	vector<unsigned long> output;

	unsigned long n;

	for (int loop = 0; loop < t; loop++)
	{
		cin >> n;

		//Separate digits
		vector <int> digits;
		int digit = 0;
		int numdigits = 0;

		do
		{
			digit = n % 10;

			digits.push_back(digit);

			n = n / 10;

			numdigits++;

		} while (n);

		//Stick the reverse
		unsigned long rev = 0;
		vector<int>::iterator it;
		

		for (it = digits.begin(); it != digits.end(); it++)
		{
			rev += (unsigned long)( (*it) * pow(10,numdigits-1) );

			numdigits--;
		}

		output.push_back(rev);
	}

	vector<unsigned long>::iterator it;
	for (it = output.begin(); it != output.end(); it++)
	{
		cout << *it<<endl;
	}

	return 0;
}