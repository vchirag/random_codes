// 339A. Helpful Maths

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	vector <int> temp;

	for(int i = 0; i < s.length(); i++)
		if(s[i] != '+')
			temp.push_back((int)s[i]);

	sort(temp.begin(), temp.end());

	for(int i = 0; i < temp.size(); i++)
	{
		s[2*i] = (char)temp[i];
	}

	cout << s;
}
