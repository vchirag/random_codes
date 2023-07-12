// 282A. Bit++

#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
	int n; 
	cin >> n;

	vector<string> instr;
	string temp;

	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		for(int j = 0; j < temp.length() - 1; j++)
		{
			if(temp[j] == '+' && temp[j+1] == '+')
			{
				sum += 1;			
			}
			else if(temp[j] == '-' && temp[j+1] == '-')
			{
				sum -= 1;
			}
			else if(temp[j] != '+' || temp[j] != '-')
				continue;
		}
	}

	cout << sum;

}
