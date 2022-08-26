#include <iostream>
#include <array>
using namespace std;

void swap(int &x, int &y)
{
	int temp;
	temp = x;
	x = y;
	y = temp;
}

void bubbleSort(int data[], int n)
{
	int temp;
	for (int i = 0; i <= (n-2); i++)
	{
		for (int j = (n-1); j >= (i+1); j--)
		{
			if(data[j] < data[j-1])
				swap(data[j-1], data[j]);
		}
	}
}

int main() {
	int arr[10] = { 18, 59, 29, 9, 6, 19, 7, 20, 5, 3 };
	bubbleSort(arr, 10);
	cout << "Sorted Array: " << endl;
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	return 0;
}