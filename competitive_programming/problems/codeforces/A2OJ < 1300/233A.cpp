// 233A. Perfect Permutation
// Nice problem

#include<iostream>
#include<vector>

using namespace std;

void swap(int &n1, int &n2)
{
	int temp;

	temp = n1;
	n1 = n2;
	n2 = temp;
}

int main()
{
	int n;
	cin >> n;

	vector <int> perm;

	if(n%2 == 0)
	{
		for(int i = 0; i < n; i++)
			perm.push_back(i+1);

		for(int i = 0; i < n; i += 2)
		{
			swap(perm[i], perm[i+1]);
		}

		for(int i = 0; i < n; i++)
			cout << perm[i] <<" ";
	}

	else
		cout << "-1";
}
