//A. Is your horseshoe on the other hoof?

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	
	typedef long long ll;

	vector <ll> s;

	ll temp;

	for(int i = 0; i < 4; i ++)
	{
		cin >> temp;
		s.push_back(temp);
	}	

	sort(s.begin(), s.end());

	int ctr = 0;

	for (int i = 0; i < 3; i++)
		if(s[i] == s[i+1])
			ctr++;

	cout << ctr;
}
