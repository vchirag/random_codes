/*
For input 4, 
D
C D
B C D
A B C D


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

	for(int i = n; i > 0; i--)
	{
		for(int j = 0; j <= n - i; j++)
		{
			std::cout << (char)(ch + i + j - 1) <<" ";
		}
		std::cout << "\n";
	}
}
