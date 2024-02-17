#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, w[10][10], ans = 1e8;
vector<int> route; 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cin>>w[i][j];
		route.push_back(i);
	}
			
	do
	{
		int sum = w[route[n-1]][route[0]];
		sum = (sum == 0 ? 1e8 : sum);
		for(int i=1; i<n; i++)
		{
			const int dist = w[route[i-1]][route[i]];
			sum += (dist == 0 ? 1e8 : dist);
		}
		ans = min(ans, sum);
	}while(next_permutation(route.begin(), route.end()));
	cout<<ans<<'\n';
	
	return 0;
}
