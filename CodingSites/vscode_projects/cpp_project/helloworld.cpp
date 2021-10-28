#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <numeric>
#include <math.h>

class Animal
{
private:
	double height;
	double weight;

	std::string name;

public:
	std::string GetName() { return name; }

	void SetName(std::string name1)
	{
		this->name = name1;
	}

	Animal()
	{
		height = 0;
		weight = 0;
	}
};

int main()
{
	int test = 0;
	
	test++;

	return 0;
}
