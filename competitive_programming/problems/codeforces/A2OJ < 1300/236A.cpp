// 236A. Boy or Girl
#define loop(i, start, end) for(int i = start; i < end; i++)

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main()
{
	string s;
	cin >> s;

	int ctr = s.length();
	
	sort(s.begin(), s.end());

	loop(i, 0, s.length()-1)
		if(s[i] == s[i+1])
			ctr--;

	if(ctr%2 == 0)
		cout << "CHAT WITH HER!";
	else
		cout << "IGNORE HIM!";

}
