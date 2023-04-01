#include <bits/stdc++.h>
using namespace std;

int n, cnt, flag = 0;
vector<string> str; 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;

	str = vector<string>(n);
	for(int i=0; i<n; i++)
		cin>>str[i];

	bool bIsDecrease = str[1] <= str[0];
	bool bIsIncrease = str[1] >= str[0];
	for(int i=2; i<n; i++)
	{
		if(bIsDecrease && str[i][0] > str[i-1][0]) bIsDecrease = false;
		if(bIsIncrease && str[i][0] < str[i-1][0]) bIsIncrease = false;
	}
	if(bIsIncrease) cout<<"INCREASING\n";
	else if(bIsDecrease) cout<<"DECREASING\n";
	else cout<<"NEITHER\n";
	
	return 0;
}
