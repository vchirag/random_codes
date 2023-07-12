// To find the sum of all the primes below two million.

// Beware of the data type used!


#include<iostream>
#include<unordered_map>

int main()
{
	unsigned long long boundU = 2000000;

	std::unordered_map <unsigned long long, bool> prime_array;

	prime_array[0] = false;
	prime_array[1] = false;


	// from numbers 2 to upper bound, value has been put as true.
	for(unsigned long long i = 2; i <= boundU; i++)
		prime_array[i] = true;

	// finding primes upto the upper bound

	for(unsigned long long i = 0; i*i <= boundU; i++)
		if(prime_array[i] == true)
			for(unsigned long long j = i*i; j <= boundU; j+=i)
				prime_array[j] = false;

	unsigned long long sum = 0;

	for(unsigned long long i = 0; i <= boundU; i++)
		if(prime_array[i] == true)
			sum += i;

	std::cout << sum;

}
