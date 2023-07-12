/*
For input n, print
1
2 1
3 2 1
4 3 2 1 
...
n times
*/


#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	for(int i = n; i > 0; i--)
	{
		for(int j = n+1; j > i; j--)
		{
			std::cout << j - i << " "; 
		}
		std::cout << "\n";	
	}
}
