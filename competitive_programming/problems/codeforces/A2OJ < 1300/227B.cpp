// // 227B. Effective Approach

// Looked up the solution for this- a very cool approach

// #include<iostream>
// #include<utility>

// using namespace std;

// pair<int,int> linSearch(int arr[], int n, int key)
// {
// 	pair<int, int> idx;
// 	int temp;

// 	for(int i = 0; i < n; i++)
// 		if(arr[i] == key)
// 		{
// 			temp = i;
// 			break;
// 		}	

// 	idx.first = temp+1;
// 	idx.second =  (n- temp);

// 	return idx;
// }


// int main()
// {
// 	int n, m;
// 	int a[99999], b[99999];

// 	cin >> n;

// 	for(int i = 0; i < n; i++)
// 		cin >> a[i];

// 	cin >> m;

// 	for(int i = 0; i < m; i++)
// 		cin >> b[i];

// 	pair<int, int> ctr;
// 	ctr.first = 0;
// 	ctr.second = 0;

// 	for(int i = 0; i < m; i++)
// 	{
// 		ctr.first += linSearch(a, n, b[i]).first;
// 		ctr.second += linSearch(a, n, b[i]).second;
// 	}

// 	cout << ctr.first << " " << ctr.second;

// }

#include<iostream>
#include<utility>

using namespace std;

int main()
{
	long long n;
	long long a[100001];

	cin >> n;

	for(long long i = 1; i <= n; i++)
		cin >> a[i];

	// Make index substituted arrays;
	long long front[100001], back[100001];

	for(long long i = 1; i <= n; i++)
		front[a[i]] = i;

	for(long long i = n; i >= 1; i--)
		back[a[i]] = n - i + 1;

	long long m;

	cin >> m;

	long long b;

	pair<long long, long long> ctr;
	ctr.first = 0;
	ctr.second = 0;

	for(int i = m; i >= 1; i--)
	{
		cin >> b;
		ctr.first += front[b];
		ctr.second += back[b];
	}

	cout << ctr.first <<  " " << ctr.second;
}
