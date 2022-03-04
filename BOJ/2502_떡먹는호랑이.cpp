#include <iostream>
#include <cstring>
using namespace std;

int d, k;
int cache[31][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>d>>k;
	
	cache[0][0] = cache[1][1] = 1;
	for(int i=2; i<d; i++)
		for(int j=0; j<2; j++)
			cache[i][j] = cache[i-1][j] + cache[i-2][j];
	
	const int p = cache[d-1][0];
	const int q = cache[d-1][1];
	for(int a=1; a*p<=k; a++)
		if((k-p*a)%q == 0)
		{
			int b = (k-p*a)/q;
			cout<<a<<'\n'<<b<<'\n';
			break;
		}

	return 0;
}
