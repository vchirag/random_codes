/*
For input 3, 
A
BC
DEF

Similarly, print for any input <= 26
*/


#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	char ch = 'A';
	int ctr = 0;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			std::cout << (char)(ch + ctr) << " "; 
			ctr += 1;
		}
		std::cout << "\n";
	}
}
