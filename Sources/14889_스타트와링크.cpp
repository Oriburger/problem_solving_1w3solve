#include <iostream>
using namespace std;

int n, s[21][21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			cin>>s[i][j];
	
	
	
	return 0;
}
