#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
int t, num;

void getAnswer(int k)
{
	for(int i=2; i<=k; i++)
		if(k%i == 0)
		{
			ans[i]++;
			return getAnswer(k/i);
		}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>t;

	while(t--)
	{
		cin>>num;
		ans = vector<int>(num+1, 0);

		getAnswer(num);

		for(int i=2; i<=num; i++)
			if(ans[i]>0) cout<<i<<" "<<ans[i]<<'\n';
	}
	
	return 0;
}
