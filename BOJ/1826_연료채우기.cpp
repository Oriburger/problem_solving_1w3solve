#include <iostream>
#include <vector>
#include <queue>
#include <vector> 
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n, l, p, ans;
vector<P> arr;
priority_queue<int> pq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=0; i<n; i++)
	{
		int a, b; 
		cin>>a>>b;
		arr.push_back({a, b}); 
	}
	cin>>l>>p;
	sort(arr.begin(), arr.end()); //거리 순으로 정렬

	int idx = 0, curr = 0;
	while(p < l) //도달할 때까지 반복
	{
    //현재 연료로 갈 수 있는 가능한 모든 주유소를 최대-힙에 넣음
		while(idx<n && p >= arr[idx].first)
		{
			pq.push(arr[idx].second);
			idx += 1;
		}
		if(pq.empty()) //도중에 도달할 수 있는 곳이 하나도 없다면? 정답은 -1
		{
			ans = -1;
			break; 
		}

		p += pq.top(); //현재 위치의 연료에 더함, 거리 시뮬레이션을 할 필요는 없음
		pq.pop(); //방문한 지점은 힙에서 pop
		ans += 1; //정답 갱신
	}
	cout<<ans<<'\n';
	
	return 0;
}
