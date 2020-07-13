#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int, int> P;

int n, ans;
vector<P> sc;
vector<int> seat;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	sc.resize(n);
	seat.resize(n);

	for(int i=0; i<n; i++)
		cin>>sc[i].first>>sc[i].second;
	sort(sc.begin(), sc.end());

	priority_queue<P, vector<P>, greater<P> > pq;
	set<int> idSet; //현재 사용이 가능한 자리들

	for(int i=0; i<n; i++) 
		idSet.insert(i);

	pq.push({sc[0].second, 0});
	seat[0]+=1; idSet.erase(pq.top().second);

	for(int i=1; i<n; i++)
	{
		int id = 0;

		//가장 빨리 끝날 예정인 pc의 종료시간이
		//다음 예정된 pc 스케쥴의 시작시간 이후이면
		if(pq.top().first > sc[i].first)
		{
			if(!idSet.empty()) id = *(idSet.begin());
			else id = 0;
			
			seat[id]++; idSet.erase(id);
			pq.push({sc[i].second, id});
		}
		//다음 예정된 pc 스케쥴의 시작시간 이전이라면,
		else 
		{
			while(1)
			{
				idSet.insert(pq.top().second);
				pq.pop();
				if(pq.empty() || pq.top().first > sc[i].first) break;
			}

			if(!idSet.empty()) id = *(idSet.begin());
			else id = 0;

			seat[id]++; idSet.erase(id);
			pq.push({sc[i].second, id});
		}
	
		ans = max(ans, (int)pq.size());
	}

	cout<<ans<<'\n';
	for(int i=0; i<ans; i++)
		cout<<seat[i]<<' ';

	return 0;
}
