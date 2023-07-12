// 80A. Panoramix's Prediction

#include<iostream>

using namespace std;

int isprime(int n)
{
	int flag = 1;

	for(int i = 2; i < n; i++)
		if(n%i == 0)
		{
			flag = 0;
			break;
		}

	if(flag == 0)
		return 0;
	else
		return 1;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int num = 0;

	for(int i = n+1; i <= m; i++)
		if(isprime(i))
		{
			num = i;
			break;
		}	

	if(num == m)
		cout << "YES";
	else
		cout << "NO";
}
