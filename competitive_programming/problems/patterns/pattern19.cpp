/*
For input 4, 
   *
  **
 ***
****

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
			if (j < n - i - 1)
				std::cout << " ";
			else
				std::cout << "*";
		}
		std::cout << "\n";
	}
}
