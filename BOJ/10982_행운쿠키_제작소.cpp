#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_T = 100001;
const int INF = 2147000000;

int t, n;
vector<int> a, b;
vector<vector<int> > cache;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n;

		a = b = vector<int>(n, 0);
		cache = vector<vector<int> >(2, vector<int>(MAX_T, INF));

		int sum = 0;
		for(int i=0; i<n; i++)
		{
			cin>>a[i]>>b[i];
			sum += a[i];
		}

		/*
		cache[i][t] : i번째 반죽에서 A가 t만큼 작동했을때의 B의 최소 작동시간
					 toggling -> 모든 cache[i][t]는 cache[i-1][t]으로만 연산
		*/

		cache[0][sum] = 0;
		cache[0][sum-a[0]] = b[0];

		int idx = 0;
		for(int i=0; i<n-1; i++)
		{
			idx = (idx+1)%2;
			int prev = (idx+1)%2;

			for(int	j=0; j<MAX_T; j++)
			{
				cache[idx][j] = INF;
				if(cache[prev][j] != INF)
				{
					cache[idx][j] = cache[prev][j]; //i+1번째 반죽을 A가 구웠을 때
					cache[idx][j-a[i+1]] = min(cache[idx][j-a[i+1]] //B가 구웠을 때
											, cache[prev][j] + b[i+1]);
				}
			}
		}

		int ans = INF;
		for(int i=0; i<MAX_T; i++)
			ans = min(ans, max(i, cache[idx][i]));
		
		cout<<ans<<'\n';
	}

	return 0;
}
