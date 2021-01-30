#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int n, m;
vector<int> plan;

bool Possible(int k)
{
	int temp=k, cnt=1;
	for(int i=0; i<n; i++)
	{
		if(plan[i]>k) return false;

		if(temp - plan[i] < 0)
		{
			temp = k;
			cnt++;
		}
		temp -= plan[i];
	}

	return cnt<=m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	plan.resize(n);
	int sum = 0;
	for(int i=0; i<n; i++)
	{
		cin>>plan[i];
		sum += plan[i];
	}

	int lo=1, hi=sum, mid=0, ans=2147000000;
	while(lo <= hi)
	{
		mid = (lo + hi)/2;

		if(Possible(mid))
		{	
			hi = mid - 1;
			ans = min(ans, mid);
		}
		else
			lo = mid + 1;
	}

	cout<<ans<<'\n';

	return 0;
}
