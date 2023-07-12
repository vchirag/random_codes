/*
For input 4, 
   1
  23
 456
78910

Similarly, print for any input.
****1
***23
**456
*78910
1112131415
*/

// Couldn't do this using the two-loop approach

#include<iostream>

int main()
{
	int n = 0;

	std::cout << "Enter n: ";
	std::cin >> n; 

	int ctr = 0;	// A counter to count the spaces
	int ctr_add = 1;	// A counter to add up to values

	for(int i = 0; i < n; i++)
	{
		ctr = n - (i + 1);
		for(int j = 0; j < ctr; j++)
		{
			std::cout << " ";
		}
		

		for(int k = 0; k <= i; k++)
		{
			std::cout << ctr_add;
			ctr_add += 1;
		}
		std::cout << "\n";
	}

}



	// int ctr = 0;

	// for(int i = 0; i < n; i++)
	// {
	// 	ctr = (i+1);

	// 	for(int j = 0; j < n; j++)
	// 	{
	// 		if(j < n- ctr)
	// 			std::cout << " ";
	// 		else
	// 			std::cout << i + j - n + 1;
	// 	}

	// 	std::cout << "\n";
	// }
