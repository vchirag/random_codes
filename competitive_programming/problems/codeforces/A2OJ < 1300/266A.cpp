// 266A. Stones on the table

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int n;
	string s;

	cin >> n >> s;

	int ctr = 0;

	for(int i = 1; i < s.length(); i++)
		if((s[i-1] == s[i]))
			ctr += 1;

	cout << ctr;
}
