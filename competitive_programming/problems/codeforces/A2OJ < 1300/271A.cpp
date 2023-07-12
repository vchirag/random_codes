// 271A. Beautiful Year

#include<iostream>
#include<vector>

using namespace std;

std::vector <int> digits_calc(int num, int divisor)
{
	std::vector <int> arr_digits;

	int digit = 0; 

	while(divisor >= 1)
	{
		digit = num/divisor;	
		arr_digits.push_back(digit);
		num = num - digit*divisor;
		divisor = divisor/10;
	}

	return arr_digits;
}

int main()
{
	int n, year;
	cin >>n;

	int unit, tens, hundreds, thousands;
	for(int i = n+1; i <= 9999; i++)
	{	
		unit = digits_calc(i ,1000)[0];
		tens = digits_calc(i ,1000)[1];
		hundreds = digits_calc(i ,1000)[2];
		thousands = digits_calc(i ,1000)[3];

		if(unit!=tens && unit!=hundreds && unit!=thousands)
			if(tens!=hundreds && tens!= thousands)
				if(hundreds!=thousands)
				{
					year = i;
					break;
				}
	}

	cout << year;
}
