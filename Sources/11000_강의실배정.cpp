#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int,int> P;

int n;
priority_queue<int, vector<int>, greater<int> > pq;
vector<P> schedule;
vector<int> seat;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int p, q; cin>>p>>q;
		schedule.push_back({p, q});
	}
	sort(schedule.begin(), schedule.end());

	pq.push(schedule[0].second);
	for(int i=1; i<n; i++)
	{
		//pq에 들어간 강의들 중에서 가장 빨리 끝나는 강의의 마치는 시간이
		//[i]번쨰로 빨리 시작하는 강의의 시작 시간 이전 이라면,
		if(pq.top() <= schedule[i].first) 
		{
			pq.pop();
			pq.push(schedule[i].second);
		}
		//이번 강의가 pq top의 강의 종료 시간 이전에 예정되어있다면,
		else
		{
			pq.push(schedule[i].second);
		}
	}

	cout<<pq.size()<<'\n';
	

	return 0;
}
