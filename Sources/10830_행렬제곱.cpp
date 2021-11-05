#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> V1st;
typedef vector<vector<ll>> V2nd;

ll n, b;
V2nd A;

V2nd operator*(const V2nd &p1, const V2nd &p2)
{
	V2nd ret = V2nd(n, V1st(n, 0));
	
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				ret[i][j] = (ret[i][j] + p1[i][k] * p2[k][j])%1000;

	return ret;
}

V2nd Square(V2nd &m, ll k)
{
	if(k==1) return m;
	else if(k%2==0){
		V2nd temp = Square(m, k/2);
		return temp * temp;	
	}
	return Square(m, k-1) * m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>b;
	
	A = V2nd(n, V1st(n, 0));
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>A[i][j];
	
	A = Square(A, b);
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<A[i][j]%1000<<' ';
		cout<<'\n';
	}

	return 0;
}
