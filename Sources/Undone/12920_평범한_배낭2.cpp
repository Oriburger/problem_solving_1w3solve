#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 10001;
const int MAX_M = 10001;
const int INF = 2147000000;
typedef long long ll;

struct info{ int v; int c; };

int n, m;
int cache[MAX_N][MAX_M];
vector<info> arr;

//idx 차례이고, 가방에 남은 무게가 w일때 얻을 수 있는 최대 만족도
int GetAnswer(int idx, int w)
{
	if(idx==n || w==0) return 0;

	int &ret = cache[idx][w];
	if(ret != -1) return ret; 

	ret = GetAnswer(idx+1, w);
	
	if(w - arr[idx].v >= 0)
		ret = max(ret, GetAnswer(idx+1, w - arr[idx].v) + arr[idx].c);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++)
	{
		int v, c, k;
		cin>>v>>c>>k;

		int tmp = 16384;

		while(k)
		{
			if(k <= tmp && tmp != 1) tmp/=2;
			else
			{
				arr.push_back({tmp * v, tmp * c});
				k -= tmp;
			}
		}
	}
	n = arr.size();
	
	cout<<GetAnswer(0, m)<<'\n';

	return 0;
}
