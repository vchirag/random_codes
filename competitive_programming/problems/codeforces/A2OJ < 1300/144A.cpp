// 144A. Arrival of the General
// Someohow the solution is incorrect (in some testcase)

#include<iostream>

using namespace std;

void swap(int &n1, int &n2)
{
	int temp;

	temp = n1;
	n1 = n2;
	n2 = temp;
}

int min(int arr[], int n)
{
	int min = arr[0];
	int idx = 0;

	for (int i = 1; i < n; i++)
		if(arr[i] <= min)
		{
			min = arr[i];
			idx = i;
		}

	return idx;
}

int max(int arr[], int n)
{
	int max = arr[0];
	int idx = 0;

	for (int i = 1; i < n; i++)
		if(arr[i] >= max)
		{
			max = arr[i];
			idx = i;
		}

	return idx;
}

int main()
{
	int n;
	cin >> n;

	int soldiers[100];

	for(int i = 0; i < n; i++)
		cin >> soldiers[i];

	int time = 0;

	int idx;
	// Find minimum index
	idx = min(soldiers, n);


	// swap minimum to the end;

	for(int i = idx; i < n-1; i++)
	{
		swap(soldiers[i], soldiers[i+1]);
		time += 1;
	}

	// FInd maximimum index
	idx = max(soldiers, n);

	// swap maximum to the front;

	for(int i = idx; i >0; i--)
	{
		swap(soldiers[i], soldiers[i-1]);
		time += 1;
	}

	// for(int i = 0; i< n; i++)
	// 	cout << soldiers[i] << " ";

	cout << time;
}
