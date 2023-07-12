// 275A. Lights Out
// Any better alternative?

#include<iostream>

using namespace std;

void toggle(bool &x)
{
	if(x == 1)
		x = 0;
	else
		x = 1;
}

int main()
{
	int toggles[3][3];
	bool lights[3][3] = {1, 1, 1,
						1, 1, 1,
						1, 1, 1};

	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> toggles[i][j];

	
	if((toggles[0][0] + toggles[0][1] + toggles[1][0])%2 != 0)
		toggle(lights[0][0]);

	if((toggles[0][0] + toggles[0][1] + toggles[0][2] + toggles[1][1])%2 != 0)
		toggle(lights[0][1]);

	if((toggles[0][2] + toggles[0][1] + toggles[1][2])%2 != 0)
		toggle(lights[0][2]);

	if((toggles[1][0] + toggles[0][0] + toggles[2][0] + toggles[1][1])%2 != 0)
		toggle(lights[1][0]);

	if((toggles[1][1] + toggles[1][0] + toggles[0][1] + toggles[1][2] + toggles[2][1])%2 != 0)
		toggle(lights[1][1]);

	if((toggles[1][2] + toggles[1][1] + toggles[0][2] + toggles[2][2])%2 != 0)
		toggle(lights[1][2]);

	if((toggles[2][0] + toggles[1][0] + toggles[2][1])%2 != 0)
		toggle(lights[2][0]);

	if((toggles[2][1] + toggles[2][0] + toggles[1][1] + toggles[2][2])%2 != 0)
		toggle(lights[2][1]);

	if((toggles[2][2] + toggles[2][1] + toggles[1][2])%2 != 0)
		toggle(lights[2][2]);

	for(int i = 0; i < 3; i++)
	{		
		for(int j = 0; j < 3; j++)
			cout << lights[i][j];
		cout << endl;
	}
}
