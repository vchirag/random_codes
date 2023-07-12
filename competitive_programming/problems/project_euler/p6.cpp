/*
Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include<iostream>

int main()
{
	long int sum_of_squares = 0;
	long int square_of_sum = 0;

	long int sum = 0;

	int boundL = 1, boundU = 100;

	for(int i = boundL; i <= boundU; i++)
	{
		sum += i;
		sum_of_squares += i*i;
	} 

	square_of_sum = sum*sum;

	std::cout << square_of_sum - sum_of_squares;
}
