#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, t;
int k[101], s[101];
int cache[10001][101];

int GetAnswer(int remain, int idx)
{
	if(idx==n) return 0;

	int &ret = cache[remain][idx];
	if(ret!=-1) return ret;

	ret = GetAnswer(remain, idx+1);
	
	if(remain >= k[idx])
		ret = max(ret, GetAnswer(remain-k[idx], idx+1)+s[idx]);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>t;

	for(int i=0; i<10001; i++)
		memset(cache[i], -1, sizeof(int)*n);

	for(int i=0; i<n; i++)
		cin>>k[i]>>s[i];

	cout<<GetAnswer(t, 0)<<'\n';

	return 0;
}
