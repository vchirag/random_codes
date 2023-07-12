/*
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
// Basic concept used is :
// For two numbers a and b, their product ab is equal to the product of their lcm(a,b) and their gcd(a,b).
// Okay, so the initial problem that I faced was with the appropriate data type to assign to the variables.
// Initially, I assigned integer datatype which returned an answer 18044195- the wrong answer.
// However, changing int to long solved the  memory overflow problem.


#include<iostream>
#include<vector>

long gcd(long n1, long n2)
{
	if(n1 == 0)
		return n2;
	return gcd(n2%n1, n1);
}

int main()
{
	std::vector <long> factors;

	for(long i = 1; i <= 20; i++)
		factors.push_back(i);

	long hcf = 0;

	long i = 0;
	long n1 = factors[0];

	long int lcm = 1;

	for (long i = 1; i < factors.size(); i++)
	{
		n1 = lcm;
		lcm = (n1*factors[i])/gcd(n1, factors[i]);
	}

	std::cout << lcm;
}
