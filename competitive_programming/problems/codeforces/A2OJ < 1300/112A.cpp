// 112A. Petya and Strings

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
	transform(s2.begin(), s2.end(), s2.begin(), ::tolower);

	int flag = 0;

	for(int i = 0; i < s1.length(); i++)
	{
		if((int)s1[i] == (int)s2[i])
			flag = 0;
		else
		{
			if((int)s1[i] < (int)s2[i])
			{
				flag = -1;
				break;
			}
			
			else
			{	
				flag = 1;
				break;
			}
		}
	}

	if(flag == 0)
		cout << "0";
	else
		if(flag == 1)
			cout << "1";
		else
			cout << "-1";
}
