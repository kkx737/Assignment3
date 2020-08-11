#include <iostream>
using namespace std;
 
void Heapify(int a[], int i, int num) //function setup to heapify the array.
{
	int data, temp;
	temp = a[i];
	data = 2*i;

 	while (data <= num)
	{
		if (data < num && a[data+1] > a[data])
		data = data+1;
		if (temp > a[data])
			break;
		else if (temp <= a[data])
		{
			a[data/2] = a[data];
			data = 2*data;
		}
	}
	a[data/2] = temp;
	return;
}
void Heap_sort(int a[], int n) //function setup for heapsort
{
	int i, temp;
	for (i = n; i >= 2; i--)
	{
		temp = a[i];  // Storing maximum value at the end.
		a[i] = a[1];
		a[1] = temp;
		Heapify(a, 1, i - 1);  // Building max heap of remaining element.
	}
}
void Maxheap(int a[], int n) //function setup to build maxheap
{
	int i;
	for(i = n/2; i >= 1; i--)
	Heapify(a, i, n);
}
int main()
{
	int n, i;
	cout<<"\nEnter the number of data element to be sorted: ";
	cin>>n;
	n++;
	int arr[n];
	for(i = 1; i < n; i++)
	{
		cout<<"Enter element "<<i<<": ";
		cin>>arr[i];
	}
	Maxheap(arr, n-1); //function calling for building max heap.
	Heap_sort(arr, n-1);

	cout<<"\nSorted Data is: ";
 
	for (i = 1; i < n; i++)
		cout<<"->"<<arr[i];
	return 0;
}