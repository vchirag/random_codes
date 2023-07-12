/*
For input n, print
1
12
123
1234
12345
...
12...n n times
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
		for(int j = 0; j <=i; j++)
		{
			std::cout << ctr << " "; 
			ctr += 1;
		}
		std::cout << "\n";
	}
}
