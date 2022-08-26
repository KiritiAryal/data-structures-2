#include<iostream>
#include <array>
using namespace std;

int arr[8];

void merge(int data[], int first, int mid, int last)
{
    int i = first, j = (mid + 1), k = first;
    while (i <= mid && j <= last)
    {
        if (data[i] <= data[j])
        {
            arr[k] = data[i];
            i++; 
            k++;
        }
        else
        {
            arr[k] = data[j];
            j++; 
            k++;
        }
    }
    if (i > mid) 
    {
        while (j <= last)
        {
            arr[k] = data[j]; 
            j++;
            k++;
        }
    }
    else
    {
        while (i <= mid)
        {
            arr[k] = data[i]; 
            i++;
            k++;
        }
    }
    for (k = first; k <= last; k++)
    {
        data[k] = arr[k];
    }
}

void mergesort(int data[], int first, int last)
{
    int mid;
    if (first < last)
    {
        mid = (first + last)/ 2;
        mergesort(data, first, mid);
        mergesort(data, (mid + 1), last);
        merge(data, first, mid, last);
    }
}
int main()
{
    int data[] = {9, 29, 7, 19, 5, 20, 13, 12};
    int n, firstEl = 0;
    n = sizeof(data)/ sizeof(int);
    cout << "Unsorted Array: ";
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
    mergesort(data, firstEl, (n-1));
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
}