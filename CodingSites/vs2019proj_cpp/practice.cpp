#if 0

#include <iostream>

inline void print(int* out)
{
	for (int i = 0; i < 5; i++)
	{
		printf("%d", out[i]);
	}
}

int arr[5] = { 1,6,9,2,4 };

void recurseperm(int index)
{



	index++;
	if (index == 5)
	{
		return;
	}
}

int main()
{
	int out[5];

	printf("Printing permutation\n");
	short size = 5;
	for (int i = 0; i < 1<<size; i++)
	{
		memset(out, 0, 5*sizeof(int));
		for (int bit = 0; bit < size; bit++)
		{
			if ( i & 1<<bit)
			{
				out[bit] = arr[bit];
			}
		}

		print(out);
		printf("\n");
	}


	printf("Permutatoin by recurssion\n");
	recurseperm(0);

	return 0;
}

#endif