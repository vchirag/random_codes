// 34A. Reconnaissance 2

#include<iostream>
#include<math.h>
#include<utility>
#include<vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> ht;

	int temp;

	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		ht.push_back(temp);
	}

	int min = 1000;
	pair<int, int> idx;

	for(int i = 0; i < ht.size() - 1; i++)
	{
		if(abs(ht[i] - ht[i+1]) <= min)
		{
			min = abs(ht[i] - ht[i+1]);
			idx.first = i + 1;
			idx.second = i + 2;
		}
	}

	if(abs(ht[0]-ht[n-1]) <= min)
	{
		idx.first = n;
		idx.second = 1;
	}

	cout << idx.first << " " << idx.second;
}
