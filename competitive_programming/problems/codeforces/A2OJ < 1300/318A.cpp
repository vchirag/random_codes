// 318A. Even Odds

// #include<iostream>
// #include<vector>

// using namespace std;

// int main()
// {
// 	int64_t n, k;
// 	cin >> n >> k;

// 	vector<int64_t> even, odd;

// 	for(int i = 1; i <= n; i++)
// 	{
// 		if(i%2 == 0)
// 			even.push_back(i);
// 		else
// 			odd.push_back(i);
// 	} 

// 	vector<int64_t> order = odd;
// 	order.insert(order.end(), even.begin(), even.end());

// 	cout << order[k-1];
// }


#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	typedef long long ll;
	
	ll n, k;
	cin >> n >> k;

	ll partition = (n + 1)/2;

	if(k <= partition)
		cout << 2*k - 1;
	else
		cout << 2*(k - partition);
}
