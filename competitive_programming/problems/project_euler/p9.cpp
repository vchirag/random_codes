/*
To find the product of the pythagorean triplet abc s.t. a < b < c s.t. a^2 + b^2 = c^2 for a+b+c = 1000.
*/

#include<iostream>
#include<cmath>

int main()
{
	int boundU = 1000;

	int c = 1;

	int max = 1;

	for(int  a = 1; a <= boundU; a++)
		for(int b = a; b <= boundU; b++)
		{
			c = 1000 - (a+b);

			if(b < c)
				if(a+b+c == 1000)
					if(pow(a, 2) + pow(b, 2) == pow(c, 2))
						if(a*b*c >= max)
							max = a*b*c;
		}

	std::cout << max;

}
