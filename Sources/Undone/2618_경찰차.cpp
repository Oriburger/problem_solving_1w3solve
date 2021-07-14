/*

	N개의 동서방향 도로, N개의 남북방향 도로
	- 도로에는 도로 번호가 존재 (1~N)
	- 도로 사이 거리는 모두 1

	도시에는 두 대의 경찰차
	- 경찰차1의 초기위치 (1,1)
	- 경찰차2의 초기위치 (N,N)
	- 사건이 발생하면, 둘 중 하나가 처리
	- 사건을 처리하면 해당 위치에서 대기
	
	사건이 발생한 순서대로 두 대의 경찰차에 맡기려고함
	- 두 대의 경찰차가 이동하는 거리의 합이 최소가 되도록

*/

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

	int next = max(pa, pb) + 1;

	ret = min(ret, GetAnswer(next, pb) + GetDist(pa, next));
	ret = min(ret, GetAnswer(pa, next) + GetDist(pb, next));

	return ret;
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

	return 0;
}

