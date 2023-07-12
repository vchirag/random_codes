/*
For input 4, 
1111
 222
  33
   4

Similarly, print for any input.
*/


#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	int ctr = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (j < ctr)
				std::cout << " ";
			else
				std::cout << ctr + 1;
		}
		std::cout << "\n";
		ctr += 1;
	}
}
