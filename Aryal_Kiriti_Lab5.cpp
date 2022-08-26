#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> costVector;
vector<int> store;

int main()
{
	deque <int> sharesQueue;
	int soldShares;
	int sellingPrice;

	int gainedShares = -1;
	int costPrice = -1;

	std::cout << "Enter the no. of shares(Enter 0 when done): ";
	while (!gainedShares == 0)
	{
		cin >> gainedShares;
		if (gainedShares != 0)
		{
			sharesQueue.push_back(gainedShares);
		}
	}
	std::cout << endl;
	std::cout << "Enter the cost of each share for these transactions respectively(Enter 0 when done): ";
	while (!costPrice == 0)
	{
		cin >> costPrice;
		if (costPrice != 0)
		{
			costVector.push_back(costPrice);
		}
	}
	std::cout << endl;
	std::cout << "Enter how many shares were sold: ";
	cin >> soldShares;
	std::cout << endl;
	std::cout << "And at what cost were these shares sold?: ";
	cin >> sellingPrice;
	cout << endl;
	int total = 0;
	while (!(total == soldShares))
	{
		int j = 0;
		while(!(sharesQueue.empty() == true))
		{
			int i = sharesQueue.front();
			if (soldShares >= i)
			{
				store.push_back(i);
				total += store[j];
					
			}
			else
			{
				store.push_back(soldShares - total);
				total += (soldShares - total);
			}
			j++;
			sharesQueue.pop_front();
		}
	}

	int capital = 0;
	for (int i = 0; i < store.size(); i++)
	{
		int num;
		if (sellingPrice >= costVector[i])
		{
			num = sellingPrice - costVector[i];
			capital = capital + (store[i] * num);
		}
		else
		{
			num = costVector[i] - sellingPrice;
			capital = capital - (store[i] * num);
		}
	}
	if (capital >= 0)
		std::cout << endl << "Capital gain: " << capital << endl;
	else
		std::cout << endl << "Capital loss: " << capital << endl;
	return 0;
}