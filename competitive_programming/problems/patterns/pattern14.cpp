/*
For input 3, 
ABC
BCD
CDE

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
		for(int j = 0; j < n; j++)
		{
			std::cout << (char)(ch + j + ctr) << " "; 
		}
		ctr += 1;
		std::cout << "\n";
	}
}
