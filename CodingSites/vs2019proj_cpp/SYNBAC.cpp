#if 0

#include <iostream>
#include <unordered_map>

using namespace std;

// genome of bacteria - collection of nucleotide, length n, A C T G 1 to 4
	// reverse
	// mutate
#define MAX_NUCLEOTIDE (4)

string genome;
int n; // genome length
unordered_map<char, int> nucleotonum;
char nucleo[MAX_NUCLEOTIDE] = {'A', 'C', 'T', 'G'};


// bacteria can produce protien p with length l 
// protien - collection of amino acids

// amino acid - encoded as condon
// condon - collection of three nucleotide
#define SIZE_CONDON (3)
unordered_map<string, char> condontoaminoacid;

int m; // protiens required

// cost calculation inputs
unordered_map<string, int> protcost;	//buying from market
int k, a;								//reverse/mutation operation cost calculation inputs
int b[MAX_NUCLEOTIDE][MAX_NUCLEOTIDE];

//Synthesize atleast 50
//Multiple condons can map to same amino acid
//amino acid count - 20
//Perform minimum genetic operations

int main()
{
	freopen("input.txt", "r", stdin);

	nucleotonum['A'] = 1;
	nucleotonum['C'] = 2;
	nucleotonum['T'] = 3;
	nucleotonum['G'] = 4;

	cin >> n >> m >> k >> a;

	for (int i = 0; i < m; i++)
	{
		string p;
		int c;
		cin >> p >> c;
		
		protcost[p] = c;
	}

	cin >> genome;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> b[i][j];
		}
	}

	for (int i = 0; i < 64; i++)
	{
		char str[4];
		cin >> str;
		char condon[SIZE_CONDON+1] = {str[0], str[1], str[2], '\0'};
		char amino = str[3];
		condontoaminoacid[condon] = amino;
	}

	return 0;
}

#endif