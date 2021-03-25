#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 101;
const int INF = 2147000000;

int n, m;
int mem[MAX], cost[MAX];
int cache[MAX][MAX];

int Answer(int curr, int idx)
{
	if(idx==n) return (curr < m ? INF : 0);

	int &ret = cache[curr][idx];
	if(ret != INF) return ret;

	ret = Answer(curr, idx+1);

	if(curr < m)
		ret = min(ret, Answer(curr+mem[idx], idx+1) + cost[idx]);

	return ret;
}	

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	fill(&cache[0][0], &cache[MAX-1][MAX-1], INF);
	for(int i=0; i<n; i++) cin>>mem[i];
	for(int i=0; i<n; i++) cin>>cost[i];
	
	cout<<Answer(0, 0)<<'\n';

	return 0;
}
