#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b, c;
vector<int> ans;

int GCD(int p, int q)
{
	if(p==0 || q==0) return p==0 ? q : p;
	else if(p==q) return p;

	if(p<q) swap(p, q);

	return GCD(p%q, q);
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

		for(int c=1; c<n; c++)
		{
			for(int b=c+1; b<n; b++)
			{
				int a = n - (c + b);
				if(a==b || a==c || b==c) continue;

				if(GCD(a, b)==c)
				{
					ans = {a, b, c};
					break;
				}
			}
			if(ans.size()>0) break;
		}

		cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';
		ans.clear();
	}

	return 0;
}
