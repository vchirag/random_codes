/*
For input n, print
1
22
333
4444
55555
...
nn...n n times
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
			std::cout << i+1 <<""; 
		}
		std::cout << "\n";
	}
}
