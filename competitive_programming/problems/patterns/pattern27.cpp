/*

For n = 5
1 2 3 4 5 5 4 3 2 1
1 2 3 4 * * 4 3 2 1
1 2 3 * * * * 3 2 1
1 2 * * * * * * 2 1
1 * * * * * * * * 1
*/


#include<iostream>

int main()
{
	int n = 0;
	
	std::cout << "Enter n: ";
	std::cin >> n;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(j <= n - i + 1)
				std::cout << j;
			else
				std::cout << "*";
		}
		
		for(int k = n; k >= 1; k--)
		{
			if(k <= n - i + 1)
				std::cout << k;
			else
				std::cout << "*";
		}
		std::cout << "\n";
	}


}
