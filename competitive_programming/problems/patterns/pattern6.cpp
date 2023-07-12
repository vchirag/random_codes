/*
For input n, print
*
**
***
****
*****
...
**...* n times
*/


#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <=i; j++)
		{
			std::cout << "* "; 
		}
		std::cout << "\n";
	}
}
