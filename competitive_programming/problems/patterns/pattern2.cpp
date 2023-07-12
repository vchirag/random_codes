/*
For a given n:
print

 1 1 1 ... n times
 2 2 2 ... n times
 3 3 3 ... n times
 . . . 
 n-1 n-1 n-1 ... n times
 n n n ... n times
*/


#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n";
	std::cin >> n;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			std::cout << i+1 << " ";
		std::cout << "\n";
	}

}
