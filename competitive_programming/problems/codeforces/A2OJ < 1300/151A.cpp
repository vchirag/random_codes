// 151A. Soft Drinking

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, k, l, c, d, p, nl, np;

	cin >> n >> k >> l >> c >> d >> p >> nl >> np;


	vector<int> toast;

	toast.push_back((k*l)/nl);
	toast.push_back(c*d);
	toast.push_back(p/np);

	sort(toast.begin(), toast.end());

	cout << toast[0]/n;
}
