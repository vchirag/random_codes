/*
Each new term in the Fionacci sequence is geneerated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be
1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...
By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include<iostream>

int main()
{
	// The upper bound in the problem
	int boundU = 4000000;

	// The nth term
	int a_n = 1;

	// The (n-1)th term
	int a_n1 = 1;

	// The (n-2)th term
	int a_n2 = 1;

	// Sum of the even-valued terms
	int sum_even = 0;

	// The loop runs until the (n+1)th term is less than the upper bound

	while(a_n < boundU)
	{
		a_n = a_n1 + a_n2;
		a_n2 = a_n1;
		a_n1 = a_n;

		if(a_n % 2 == 0)
			sum_even += a_n;
	}

	std::cout << sum_even;

}
