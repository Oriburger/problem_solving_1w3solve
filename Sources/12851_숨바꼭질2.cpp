#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n, k, t=-1, cnt=0;
queue<P> q;
vector<int> visited(100001, 0);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	q.push({n, 0});
	while(!q.empty())
	{
		int cur_idx = q.front().first;
		int cur_t = q.front().second;
		q.pop();

		visited[cur_idx] = true;

		if(cur_idx == k)
		{
			t = (t==-1 ? cur_t : t);
			if(cur_t == t) cnt++;
		}

		if(t!=-1 && cur_t+1 > t) continue;

		if(cur_idx+1 < 100001 && !visited[cur_idx+1])
			q.push({cur_idx+1, cur_t+1});
		if(cur_idx-1 >= 0 && !visited[cur_idx-1])
			q.push({cur_idx-1, cur_t+1});
		if(cur_idx*2 < 100001 && !visited[cur_idx*2])
			q.push({cur_idx*2, cur_t+1});
	}

	cout<<t<<'\n'<<cnt<<'\n';

	return 0;
}
