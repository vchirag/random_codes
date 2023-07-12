/*
To print 

****
****
****
****

*/

#include<stdio.h>
#include<iostream>
// using namespace std;
int main()
{
	for(int i = 0; i < 4; i++)
	{
		for(int j =0; j < 4; j++)
			std::cout << "*";
		std::cout << "\n";

	}
}
