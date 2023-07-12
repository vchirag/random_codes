// 110A. Nearly Lucky Number

#include<iostream>
#include<string>

using namespace std;

int main()
{
	int lucky_counter = 0;

	string num;

	cin >> num;

	for(int i = 0; i < num.length(); i++)
		if(num[i] == '4' || num[i] == '7')
			lucky_counter++;

	if(lucky_counter == 4 || lucky_counter == 7)
		cout << "YES";
	else
		cout << "NO";
}
