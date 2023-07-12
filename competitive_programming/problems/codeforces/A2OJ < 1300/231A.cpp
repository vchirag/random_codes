// 231A. Team

#include<iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;

	int p[1000], v[1000], t[1000];

	int sum = 0;

	int ctr = 0;

	for(int i = 0; i < n; i++)
	{
		cin >> p[i] >> v [i] >> t[i];
		sum = p[i] + v[i] + t[i];
		if(sum > 1)
			ctr += 1;
	}

	cout << ctr;
}
