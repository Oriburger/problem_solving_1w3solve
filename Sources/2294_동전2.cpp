/*
-------------------------------------
--------  Top-Down ------------------
-------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100001;
int n, k, ans;
vector<int> coin, cache;

int GetAnswer(int val)
{
	if(cache[val]!=-1) return cache[val];
	if(val==0) return cache[val]=0;

	int ret = INF;
	cache[val] = INF;
	for(int i=0; i<n; i++)
	{
		if(val-coin[i] >= 0)
		{
			cache[val] = min(cache[val], GetAnswer(val-coin[i])+1);
			ret = min(ret, cache[val]);
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;
	cache.resize(k+1, -1);
	coin.resize(n);
	for(int i=0; i<n; i++)
		cin>>coin[i];
	
	sort(coin.begin(), coin.end());
	coin.erase(unique(coin.begin(), coin.end()), coin.end()); //중복제거 최적화

	n=coin.size();
	
	int ans = GetAnswer(k);
	
	if(ans==-1 || ans==INF) cout<<-1<<'\n';
	else cout<<ans<<'\n';

	return 0;
}

//-----------------------------------------------------------------------



/*
-------------------------------------
-------- Bottom-UP ------------------
-------------------------------------
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 100001;
int n, k;
vector<int> coin, cache;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;
	cache.resize(k+1, INF);
	coin.resize(n);
	for(int i=0; i<n; i++)
		cin>>coin[i];
	
	sort(coin.begin(), coin.end());
	coin.erase(unique(coin.begin(), coin.end()), coin.end()); //중복제거 최적화

	n=coin.size();
	
	cache[0]=0;
	for(int i=0; i<n; i++)
		for(int j=coin[i]; j<=k; j++)
			if(j-coin[i] >= 0) cache[j] = min(cache[j], cache[j-coin[i]] + 1);
	
	cout << (cache[k] == INF ? -1 : cache[k]) <<'\n';

	return 0;
}
