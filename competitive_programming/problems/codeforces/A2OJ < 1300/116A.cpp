// 116A. tram

#define loop(i, start, end) for(int i = start; i < end; i++)

#include<iostream>

using namespace std;

int main()
{
	int n;
	int enter[1000], exit[1000];

	cin >> n;

	loop(i, 0, n)
		cin >> exit[i] >> enter[i];

	int sum = enter[0];

	int cap = enter[0];

	loop(i, 1, n)
	{
		sum -= exit[i];
		sum += enter[i];

		if(sum >= cap)
			cap = sum;
	}

	cout << cap;

}
