// 272A. Dima and Friends

#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int fingers[100];
	int sum_fingers = 0;

	for(int i = 0 ; i < n; i++)
	{
		cin >> fingers[i];
		sum_fingers += fingers[i];
	}

	int ans = 0;

	for(int i = 1; i <= 5; i++)
		if((sum_fingers + i)%(n + 1) != 1)
			ans+=1;

	cout << ans;

}
