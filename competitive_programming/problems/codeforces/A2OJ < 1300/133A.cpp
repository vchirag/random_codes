#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int flag = 0;

	for(int i = 0; i < s.length(); i++)
		if((int)s[i] >= 33 && (int)s[i] <= 126)
			if((int)s[i] == 72 || (int)s[i] == 81 || (int)s[i] == 57)
			{
				flag = 1;
				break;
			}

	if(flag)
		cout << "YES";
	else
		cout << "NO";
}
