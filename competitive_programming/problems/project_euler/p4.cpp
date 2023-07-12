/*
To find: the largest palindromic number formed by multiplying two 3 digits numbers
//	 Improved upon a conditional check after reading the forum:
// A palindromic number is divisible by 11 -> one of the 3-digit numbers (as factors) must be diisible by 11.	
*/

// I liked solving this one :)


#include<iostream>
#include<vector>
#include<algorithm>


// A function to find the digits according to their place values in the given number
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

// n = no. of digits
// A function to check if the number entered is a  palindrome
// The function accepts the digits of the number as an array

int palindrome_checker(std::vector <int> digits)
{
	int n = digits.size();

	// Using two pointer approach to traverse the array
	int front = 0, back = n-1;

	// a flag variable to store the palindrome-ness of the number in consideration
	int flag = 0;
	
	while(front <= back)
	{
		if(digits[front] == digits[back])
			flag = 1;
		else
		{
			flag = 0;
			break;
		}
		front += 1;
		back -= 1;
	}

	if(flag)
		return 1;
	else
		return 0; 
}


int main()
{
	int boundL = 100, boundU = 999;

	std::vector <int> arr_num;

	// saving squares of numbers
	for(int i = boundL; i <= boundU; i++)
		if((i % 11 == 0))
			arr_num.push_back(i*i);

	// saving cross terms
	for(int i = boundL; i <= boundU; i++)
		for(int j = i+1; j <= boundU; j++)
			if((i % 11 == 0) || (j % 11 == 0))
				arr_num.push_back(i*j);

	//Sorting the vector
	std::sort(arr_num.begin(),arr_num.end());

	int max = 0;
	for(int i = 0; i <= arr_num.size(); i++)
	{
		if(arr_num[i] <= 99999)
		{
			digits_calc(arr_num[i], 10000);
			if(palindrome_checker(digits_calc(arr_num[i], 10000)))
			{
				if(arr_num[i] >= max)
					max = arr_num[i];
			}
		}
		else
		{
			digits_calc(arr_num[i], 100000);

			if(palindrome_checker(digits_calc(arr_num[i], 100000)))
			{
				if(arr_num[i] >= max)
					max = arr_num[i];
			}
		}
	}

	std::cout << max;

}
