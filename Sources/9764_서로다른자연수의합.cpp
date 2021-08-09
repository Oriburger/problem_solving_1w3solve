#include <bits/stdc++.h>
using namespace std;

const int INF = 100999;

int n;
int cache[2001][2001];

int GetAnswer(int k, int curr)
{
	if(k==0) return 1;

	int &ret = cache[k][curr];
	if(ret != 0) return ret;

	for(int i=curr+1; i<=k; i++)
		ret = (GetAnswer(k-i, i)+ret)%INF;

	return ret%INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		cin>>n;
		cout<<GetAnswer(n, 0)<<'\n';
	}

	return 0;
}
