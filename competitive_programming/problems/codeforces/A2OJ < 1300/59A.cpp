// 59A. Word

#include<iostream>
#include<string>
#include <algorithm> 


using namespace std;

int main()
{
	string s;
	cin >> s;

	int ctr_upper = 0;
	int ctr_lower = 0;

	for(int i = 0; i < s.length(); i++)
	{
		if(isupper(s[i]))
			ctr_upper += 1;
		else
			ctr_lower += 1;
	}

	if (ctr_upper > ctr_lower)
		transform(s.begin(), s.end(), s.begin(), ::toupper);
	else
	    transform(s.begin(), s.end(), s.begin(), ::tolower);

	cout << s;
}
