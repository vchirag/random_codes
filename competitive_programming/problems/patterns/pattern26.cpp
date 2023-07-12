/*
For n = 4
***1***
**121**
*12321*
1234321   
*/

#include<iostream>

int main()
{
	int n = 0;
	
	std::cout << "Enter n: ";
	std::cin >> n;

	int ctr_star = 0;

	for(int i = 1; i < n + 1; i++)
	{
		ctr_star = n - i;
		
		for(int j = 1; j < ctr_star + 1; j++)
			std::cout << "*";

		ctr_modulo = i-1;
		
		for(int k = 1; k < 2*i; k++)
		{
			if(k > i)
				std::cout << -k + 2*i;
			else
				std::cout << k;
		}

		for(int j = 1; j < ctr_star + 1; j++)
			std::cout << "*";

		std::cout << "\n";
	}
}
