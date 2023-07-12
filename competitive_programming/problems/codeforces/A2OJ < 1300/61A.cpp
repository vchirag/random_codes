 // 61A. Ultra-Fast Mathematician

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	string num1, num2;

	cin >> num1 >> num2;

	vector<int> num3;

	for(int i = 0; i < num1.length(); i++)
	{
		if(num1[i] != num2[i])
			num3.push_back(1);
		else
			num3.push_back(0);
	}

	for(int i = 0; i < num3.size(); i++)
		cout << num3[i];	
}
