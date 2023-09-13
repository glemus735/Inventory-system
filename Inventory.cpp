#include <iostream>
#include <string>
#include <time.h>
using namespace std;

// global arrays/variables 
int max1;
int letters[100];
int numbers[100];
double costs[100];

void GenerateRandomLetters();
void GenerateRandomNumbers();
void GenerateRandomCosts();

class Inventory
{
public:
	int local;
	int itemsNum[100];
	char itemsChar[100];
	double costs[100];
};

class Valuation {
	//Inventory inv;
public:
	double costs(Inventory& inv) {
		double totalCosts = 0.0;
		for (int counter = 0; counter < max1; counter++) {
			totalCosts = totalCosts + (inv.costs[counter] *
				inv.itemsNum[counter]);
		}
		return totalCosts;
	}
};

int main()
{
	// seed for the random number generator
	srand(time(NULL));

	GenerateRandomLetters();
	GenerateRandomNumbers();
	GenerateRandomCosts();

	Inventory inv;
	Valuation v;
	int totalQuantity = 0;
	double totalCost = 0;
	for (int i = 0; i <= max1; i++)
	{
		inv.itemsNum[i] = numbers[i];
		inv.itemsChar[i] = letters[i];
		inv.costs[i] = costs[i];
		totalQuantity += numbers[i]; //accumlated items 
	}
	cout << "Average cost = $ " << (v.costs(inv) / totalQuantity) << endl;
	system("PAUSE");
	return 0;
}

void GenerateRandomLetters()
{
	char randChar = '\0 ';
	int counter = 0;
	int randNum = 0;
	int maxLetters = 0;
	cout << "How many items in the inventory?" << endl;
	cin >> maxLetters;
	for (counter = 0; counter < maxLetters; counter++)
	{
		// select a number between 0 and 25
		randNum = 26 * (rand() / (RAND_MAX + 1.0));

		// use ASCII code with 'a' = 97
		// for lower case letters
		randNum = randNum + 97;
		// type cast to character
		randChar = (char)randNum;
		letters[counter] = randChar;
		printf("Inventory Item: %c\n", randChar);
	}
}
void GenerateRandomNumbers()
{
	int counter = 0;
	int maxNums = 0;
	int randNum = 0;
	cout << "How many numbers to simulate the inventory?" << endl;
	cin >> maxNums;
	max1 = maxNums;
	for (counter = 0; counter < maxNums; counter++)
	{
		randNum = 100 * (rand() / (RAND_MAX + 1.0));
		numbers[counter] = randNum;
		printf("Item Quantity: %d\n", randNum);
	}
}
void GenerateRandomCosts()
{
	int counter = 0;
	int maxNums = 0;
	int randNum = 0;
	cout << "What number of costs to generate for each inventory item?" <<
		endl;
	cin >> maxNums;
	max1 = maxNums;
	for (counter = 0; counter < maxNums; counter++)
	{
		randNum = 1 + 10 * (rand() / (RAND_MAX + 1.0));
		costs[counter] = randNum;
		printf("Item Cost: %d\n", randNum);
	}
}