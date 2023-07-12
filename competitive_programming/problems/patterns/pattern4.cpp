/*
For n input, print
 			n n-1 n-2 ... 1
 			n n-1 n-2 ... 1 
 				... 
 nth time	n n-1 n-2 ...  1

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
			std::cout << n-j <<" ";
		std::cout << "\n";
	}
}
