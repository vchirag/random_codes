// 266B. Queue at the School
// Ok, the problem with codeforces judges is that it must see the variables being accepted directly instead of a statement preceeding the variable input.
// i.e. cout << "Enter n: "; cin >> n; is unacceptable. Instead, write cin >> n;

#include<iostream>
#include<string>

using namespace std;

int main()
{

	int n, t;
	string s;

	cin >> n >> t  >> s;

	int t_instantaneous = 1;
	int i = 0;

	while(t >= t_instantaneous)
	{
		i = 0;
		while(i < n)
		{
			if(s[i] == 'B' && s[i+1] == 'G')
			{
				s[i] = 'G';
				s[i+1] = 'B';
				i += 2;
			}
			
			else
				i += 1;
		}
		t_instantaneous += 1;
	}

	cout << s<< endl;
	return 0;
}
