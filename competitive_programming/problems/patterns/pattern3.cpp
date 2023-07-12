/*
For n input, print
 			1 2 3 4 ... n
 			1 2 3 4 ... n 
 				... 
 nth time	1 2 ... n-1 n

*/

#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			std::cout << j+1 <<" ";
		std::cout << "\n";
	}
}
