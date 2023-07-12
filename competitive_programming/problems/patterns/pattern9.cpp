/*
For input n, print
1
2 3
3 4 5
4 5 6 7 
...
n times
*/


#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	int ctr = 1;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			std::cout << j + ctr << " "; 
		}
		std::cout << "\n";
		ctr += 1;
	
	}
}
