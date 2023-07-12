// 141A. Amusing Joke

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string guest, host, mix;

	cin >> guest >> host >> mix;

	guest = guest + host;

	sort(guest.begin(), guest.end());
	sort(mix.begin(), mix.end());

	int flag = 0;

	if(guest.length() != mix.length())
		flag = 0;
	else
		for(int i = 0; i < guest.length(); i++)
			if(guest[i] == mix[i])
				flag = 1;
			else
			{
				flag = 0;
				break;
			}
	if(flag)
		cout << "YES";
	else
		cout << "NO";
}
