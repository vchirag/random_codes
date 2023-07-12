// 205A. Little Elephant and Rozdil

#include<iostream>
#include<algorithm>

using namespace std;

int main()
{
	typedef long long ll;
	ll n;
	cin >> n;

	ll times[100000];

	for(int i = 0; i < n; i++)
		cin >> times[i];

	int min = *(min_element(times, times+n));
	int idx = find(times, times+n, min) - times;

	sort(times, times+n);

	if(times[0] == times[1])
		cout << "Still Rozdil";
	else
		cout << idx+1;

}
