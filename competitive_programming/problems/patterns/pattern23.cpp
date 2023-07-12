/*
For input 4, 
   1
  22
 333
4444

Similarly, print for any input.
*/


#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	int ctr = n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if (j < ctr-1)
				std::cout << " ";
			else
				std::cout << i + 1;
		}
		std::cout << "\n";
		ctr -= 1;
	}
}
