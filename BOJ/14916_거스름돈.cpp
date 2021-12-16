#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int n, cache[100001];

int GetAnswer(int k)
{
	int &ret = cache[k];
	if(ret != -1) return ret;
	if(k==0 || k==2 || k==5) return ret = (k ? 1 : 0);

	ret = INF;
	if(k-2 >= 0) ret = GetAnswer(k-2) + 1;
	if(k-5 >= 5) ret = min(ret, GetAnswer(k-5) + 1);
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n; 

	memset(cache, -1, sizeof(cache));
	int ans = GetAnswer(n);
	cout<<(ans >= INF ? -1 : ans)<<'\n';


	return 0;
}
