/*
The prime factors of 13195 are 5, 7, 13, 29.
To find: the largest prime factor of the number 600851475143.
*/


#include<iostream>
#include<cmath>

int main()
{
	long int num = 600851475143;
	int factor = 2;

	if(factor < sqrt(num))
	{
		while(num > 1)
		{
			if(num % factor == 0)
				num  = num/factor;
			else
				factor += 1;
		}
	}
	else
		factor = num;

	std::cout << factor;

}
