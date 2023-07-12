/*
For n = 3, print

1 2 3 
4 5 6 
7 8 9 

Similarly for n = 5, print

1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

in essence: print the above patters for any input n
*/

#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	int ctr = 0; // A counter variable to keep track of new lines

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			std::cout << (i+1) + j + ctr << " ";
		}
		ctr += n-1;
		std::cout<<"\n";
	}
	
}
