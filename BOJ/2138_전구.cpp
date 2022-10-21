#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n, ans = 1e9+1; 
string bulb[2];

void toggle(int idx)
{
	for(int i=-1; i<=1; i++)
	{
		if((idx==0 && i==-1) || (idx==n-1 && i==1)) continue;
		const int val = bulb[0][idx+i] - '0';
		bulb[0][idx+i] = (1-val) + '0';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	for(int i=0; i<2; i++)
		cin>>bulb[i];

	for(int k=0; k<=1; k++)
	{
		int temp = 0;
		string bulbCpy = bulb[0];

		if(k==1)
		{
			toggle(0);
			temp += 1; 
		}
		for(int i=1; i<n; i++)
		{
			if(bulb[0][i-1] != bulb[1][i-1])
			{
				toggle(i);
				temp += 1;
			}
		}
		if(bulb[0] == bulb[1]) 
			ans = min(ans, temp);
		bulb[0] = bulbCpy;
	}
	ans = (ans==1e9+1 ? -1 : ans); 
	cout<<ans<<'\n';
	
	return 0;
}
