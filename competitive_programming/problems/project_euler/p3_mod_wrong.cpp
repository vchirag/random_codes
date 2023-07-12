/*
The prime factors of 13195 are 5, 7, 13, 29.
To find: the largest prime factor of the number 600851475143.
*/

// Would update the solution with a much better logic
// So unknowligly, with the aid of this program I was looking for the numbers that are prime upto an Upper Bound. 
// Which astonishingly wasn't asked in the prolem! XD
// Surprisingly, the method coded in this problem is wrong!


#include<iostream>
#include<vector>
#include<algorithm>

int main()
{
	// A vector to store prime numbers encountered.
	std::vector<int> arr_prime;

	// Initializing the prime array with the first prime number i.e. 2.

	arr_prime.push_back(2);

	// Setting the upper bound to find prime numbers upto that number.
	int boundU = 20;

	// Looking for prime numbers until the dummy index reaches the upper bound.
	// We start from the next largest number than 2, i.e. 3.
	int i = 3;
	while(i <= boundU)
	{
		for(int j = 0; j < arr_prime.size(); j++)
		{
			if(i % arr_prime[j] == 0)
				break;
			else
				arr_prime.push_back(i);
		}
		i += 1;
	}

	for(int j = 0; j < arr_prime.size(); j++)
	{
		std::cout << arr_prime[j] << " ";
	}
 
 }
