#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int t, n, m;
vector<P> arr; 
vector<bool> check;

bool comp(P& p, P& q)
{
	return p.second != q.second ? p.second < q.second : p.first < q.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n>>m;

		check = vector<bool>(1001, false);

		for(int i=0; i<m; i++)
		{
			int a, b;
			cin>>a>>b;
			arr.push_back({a, b});
		}
		sort(arr.begin(), arr.end(), comp);

		int ans = 0;
		for(int i=0; i<m; i++)
		{
			for(int j=arr[i].first; j<=arr[i].second; j++)
			{
				if(!check[j])
				{
					check[j]=true;
					ans++;
					break;
				}
			}
			//cout<<p.first<<' '<<p.second<<'\n';
		}
		cout<<ans<<'\n';
		
		arr.clear();
	}

	return 0;
}
