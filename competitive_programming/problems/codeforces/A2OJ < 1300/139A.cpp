// 139A. Petr and Book

#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int pages[7];

	for(int i = 0; i < 7; i++)
		cin >> pages[i];

	int sum = pages[0];
	int i = 0;

	while(sum < n)
	{
		i += 1;
		sum += pages[i%7];
	}

	cout << i%7 + 1;
}
