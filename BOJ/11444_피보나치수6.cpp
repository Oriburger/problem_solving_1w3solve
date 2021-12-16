#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef unsigned long long ull;
typedef vector<vector<ull> > matrix;
const ull INF = 1000000007;

matrix operator * (const matrix &m1, const matrix &m2)
{
	int n = m1.size();
	matrix m3(n, vector<ull>(n));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		{
			for(int k=0; k<n; k++)
				m3[i][j] += m1[i][k] * m2[k][j];
			m3[i][j] %= INF;
		}
	return m3;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	ull n;
	cin>>n;

	if(n<=2)
	{	
		cout<<1<<'\n';
		return 0;
	}

	matrix ans = {{1, 0}, {0, 1}};
	matrix a = {{1, 1}, {1, 0}};

	while(n>0)
	{
		if(n%2 == 1)
			ans = ans * a;
		a = a * a;
		n/=2;
	}

	cout<<ans[0][1]<<'\n';

	return 0;
}
