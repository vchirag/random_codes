// To list the 10001 th prime number

// Used the method of sieve of Eratosthenes
// Upper bound was substituted with hit and trial

// 

#include<iostream>
#include<unordered_map>

int main()
{
	unsigned int ctr = 1;
	unsigned int index = 0;

	std::unordered_map <unsigned int, bool> prime_array;

	unsigned int boundU = 120000;

	// Since zero and one are not prime, their value has been substituted as false

	prime_array[0] = false;
	prime_array[1] = false;

	// from numbers 2 to upper bound, value has been put as true.
	for(unsigned int i = 2; i <= boundU; i++)
		prime_array[i] = true;

	// Finding the 10001 prime
	for(unsigned int i = 0; i*i <= boundU; i++)
		if(prime_array[i] == true)
		{	
			if(ctr == 10001)
			{
				index = i;
				break;
			}

			else
			{
				for(unsigned int j = i*i; j <= boundU; j += i)
				prime_array[j] = false;
			}
			ctr += 1;
		}

	std::cout << index;
}
