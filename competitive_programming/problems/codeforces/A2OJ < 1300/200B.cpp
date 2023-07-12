// 200B. Drinks

#define loop(i, start, end) for(int i = start; i < end; i++)

#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	int n;

	int drinks[100];

	cin >> n;

	loop(i, 0, n)
		cin >> drinks[i];

	int ans = 0;

	loop(i, 0, n)
		ans += drinks[i];

	cout << std::fixed <<setprecision(14) << (double)ans/n;
}
