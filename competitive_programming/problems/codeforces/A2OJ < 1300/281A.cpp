// 281A. Word Capitalization

#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	string s;
	cin >> s;

	s[0] = toupper(s[0]);

	cout << s;
}
