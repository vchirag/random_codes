// 155A. I_love_%username%

#define loop(i, start, end) for(int i = start; i < end; i++)

#include<iostream>

using namespace std;

int main()
{
	int n;
	int score[1000];

	cin >> n;

	loop(i, 0, n)
		cin >> score[i];

	int ctr = 0;

	int min = score[0];
	int max = score[0];

	loop(i, 1, n)
		loop(j, 0, i+1)
			{
				if(score[j] > max)
				{
					max = score[j];
					ctr += 1;
				}

				if(score[j] < min)
				{
					min = score[j];
					ctr += 1;
				}
			}

	cout << ctr;
}
