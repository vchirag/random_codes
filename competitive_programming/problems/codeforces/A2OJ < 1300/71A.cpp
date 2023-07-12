//71A. Way Too Long Words


#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{

	int n;
	cin >> n;

	vector<string> s;
	string temp;

	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		s.push_back(temp);
	}

	for(int i = 0; i < n; i++)
	{	
		temp = s[i];
		if(s[i].length() > 10)
		{	
			s[i].clear();

			s[i].push_back(temp[0]);
			s[i].append(to_string(temp.length() - 2));
			s[i].push_back(temp[temp.length() - 1]);
		}
	}

	for(int i = 0; i < n; i ++)
		cout << s[i] << "\n";





	// string s;

	// cin >> s;

	// string temp;

	// temp = s;

	// s.clear();

	// s.push_back(temp[0]);
	// s.append(to_string(temp.length() - 2));
	// s.push_back(temp[temp.length() - 1]);

	// cout << s;

}
