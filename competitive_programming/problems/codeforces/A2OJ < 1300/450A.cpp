// 450A. Jzzhu and Childern

// Why is this code wrong??? on test 6 especially?

#include<iostream>
#include<deque>

using namespace std;

int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	deque<int> a;
	deque<int> idx;

	int temp;

	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		a.push_back(temp);
		idx.push_back(i+1);
	}

	int size = a.size();

	while(size != 0)
	{
		temp = idx.front();

		if(a.front() <= m)
		{
			a.pop_front();
			idx.pop_front();
			size -= 1;
		}
		else
		{
			a.push_back(m - a.front());
			idx.push_back(idx.front());

			a.pop_front();
			idx.pop_front();
		}
	}

	cout << temp;
}
