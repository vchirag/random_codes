// 248A. Cupboards

#include<iostream>

using namespace std;

int main()
{
	long n;
	bool left[99999], right[99999];

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> left[i] >> right[i];

	int left_ctr = 0;
	int right_ctr = 0;

	int time = 0;

	for(int i = 0; i < n; i++)
	{
		if(left[i] == 0)
			left_ctr++;

		if(right[i] == 0)
			right_ctr++;
	}

	if(right_ctr <= n/2)
		time += right_ctr;
	else
		time += n - right_ctr;

	if(left_ctr <= n/2)
		time += left_ctr;
	else
		time += n - left_ctr;

	cout << time;

}
