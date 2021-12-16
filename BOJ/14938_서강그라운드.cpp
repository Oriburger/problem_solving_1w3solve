#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 101;
const int INF = 999999;

int n, m, r, ans=0;
vector<int> item(MAX_N), dist(MAX_N, INF);
vector<int> adj[MAX_N];

int main()
{
	ios::sync_with_stdio(false);
	cout.tie(NULL); cin.tie(NULL);

	cin>>n>>m>>r;

	for(int i=0; i<n; i++)
	{
		cin>>item[i];
		adj[i]=vector<int>(n, INF);
	}

	for(int i=0; i<r; i++)
	{
		int a, b, l;
		cin>>a>>b>>l;

		adj[a-1][b-1]=l;
		adj[b-1][a-1]=l;
	}

	//플로이드-워셜
	for(int k=0; k<n; k++)
	{
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				if(i==j) continue;
				if(adj[i][j] > adj[i][k] + adj[k][j])
					adj[i][j] = adj[i][k] + adj[k][j];
			}
		}
	}

	//각 도시마다의 최댓값을 비교한다.
	for(int i=0; i<n; i++)
	{
		int temp=item[i]; //내린 지점의 아이템도 get 
		for(int j=0; j<n; j++) //범위 내의 아이템을 모두 get
		{
			if(i!=j && adj[i][j] <= m)
				temp += item[j];
		}
		ans = max(ans, temp); //ans값 갱신
	}
	cout<<ans<<'\n';

	return 0;
}
