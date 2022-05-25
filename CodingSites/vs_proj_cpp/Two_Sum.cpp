#if 0

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;




#define MAX_NUM (10005)
#define MAX_NUM_SIZE (1000000000)

struct node
{
	int num;
	int index;

	int next;
};
node nodes[MAX_NUM];

struct hashnode
{
	int head = -1;
};

#define HASH_TABLE_SIZE (1000)

class hashtable
{
	int currnode = 0;
	hashnode table[HASH_TABLE_SIZE];

public:
	hashtable()
	{
		currnode = 0;
	}

	int getIndex(int num)
	{
		int hash = getHash(num);

		//assert(table[hash].head != -1);
		if (table[hash].head == -1)
		{
			return -1;
		}

		int nodeindex = table[hash].head;
		while (nodeindex != -1 && nodes[nodeindex].num != num)
		{
			nodeindex = nodes[nodeindex].next;
		}
		//assert(nodeindex != -1);
		if (nodeindex == -1)
		{
			return -1;
		}

		return nodes[nodeindex].index;
	}

	int getHash(int num)
	{
		int tableindex = num % HASH_TABLE_SIZE;

		if (tableindex < 0)
		{
			tableindex *= -1;
		}
		return tableindex;
	}

	void setIndex(int num, int index)
	{
		int hash = getHash(num);

		if (table[hash].head == -1)
		{
			table[hash].head = currnode;
		}
		else
		{
			int nodeindex = table[hash].head;
			while (nodes[nodeindex].next != -1)
			{
				nodeindex = nodes[nodeindex].next;
			}
			
			nodes[nodeindex].next = currnode;
		}
		nodes[currnode].index = index;
		nodes[currnode].num = num;
		nodes[currnode].next = -1;
		currnode++;
	}


};

hashtable *numtoindex;





class Solution {
public:

	vector<int> twoSum(vector<int>& nums, int target) {


		numtoindex = new hashtable();

		vector<int >returnSize(2);

		for (int i = 0; i < nums.size(); i++)
		{
			numtoindex->setIndex(nums[i], i);
		}

		for (int i = 0; i < nums.size(); i++)
		{
			int diff = target - nums[i];

			int index = numtoindex->getIndex(diff);
			if (index != -1 && index != i)
			{
				returnSize[0] = i;
				returnSize[1] = index;
				break;
			}
		}

		return returnSize;
	}
};



int  main()
{
	//freopen("input.txt", "r", stdin);

	//vector<int> nums = { 1 , 5, 23, -8, 2, -12, 6, 222, 543, 13 };
	vector<int> nums = { 3 , 2 , 4 };
	int target = 6;

	Solution a;
	vector<int> returnarray = a.twoSum(nums, target);

	cout << returnarray[0];
	cout << returnarray[1];
}

#endif