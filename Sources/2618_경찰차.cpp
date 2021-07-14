#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct Pos {int y; int x;};
const int INF = 2147000000;
const int M_INF = -2147000000;

int n, w;
vector<Pos> task;
int cache[1001][1001];
Pos trace[1001][1001];

inline int GetDist(int p1, int p2)
{
	return abs(task[p1].y-task[p2].y) + abs(task[p1].x-task[p2].x);
}

int GetAnswer(int pa, int pb)
{
	if(pa == w+1 || pb == w+1) return 0;
	
	int &ret = cache[pa][pb];
	if(ret != -1) return ret;

	ret = INF;

	int next, val1, val2;
	
	next = max(pa, pb) + 1;
	val1 = GetAnswer(next, pb) + GetDist(pa, next);
	val2 = GetAnswer(pa, next) + GetDist(pb, next);

	if(val1 < val2)
		trace[pa][pb] = {next, pb};
	else
		trace[pa][pb] = {pa, next};

	return ret = min(val1, val2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>w;

	task.push_back({1, 1});
	task.push_back({n, n});
	for(int i=0; i<w; i++)
	{
		int y, x;
		cin>>y>>x;
		task.push_back({y, x});
	}

	memset(cache, -1, sizeof(cache));
	cout<<GetAnswer(0, 1)<<'\n';

	int pa = 0, pb = 1;
	for(int i=2; i<=w+1; i++)
	{
		Pos next = trace[pa][pb];

		if(next.y == pa) cout<<2<<'\n';
		else cout<<1<<'\n';

		pa = next.y;
		pb = next.x;
	}

	return 0;
}

