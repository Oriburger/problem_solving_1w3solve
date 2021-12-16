#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef vector<P>::iterator viter;

struct Comp //pq를 위한 비교함수 구조체
{
	bool operator()(P& a, P& b) 
	{
		if(a.first != b.first) return a.first > b.first; //m을 기준으로 오름차순
		return a.second < b.second;	//m이 같다면? v 기준으로 내림차순 
	}
};


int n, k;
long long ans=0; //정답은 int 범위를 벗어날 수 있음
vector<int> c;
priority_queue<P, vector<P>, Comp> pq; //m을 기준으로 하는 minHeap
priority_queue<int, vector<int>> tmp; //value이 들어있는 maxHeap

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	for(int i=0; i<n; i++)
	{
		int m, v;
		cin>>m>>v;
		pq.push({m, v}); //우선순위 큐에 push
	}
	
	c = vector<int>(k, 0);
	for(int i=0; i<k; i++)
		cin>>c[i];
	
	sort(c.begin(), c.end()); //가방 크기를 오름차순으로 정렬
	for(auto &curr : c) //작은 가방부터 순회 
	{
		while(1)
		{
            //현재 가방의 용량보다 크거나 pq가 비었다면 탈출
			if(pq.top().first > curr || pq.empty()) break;

            //현재 가방에 넣을 수 있는 보석들을 최대힙 tmp에 push
			tmp.push(pq.top().second);
			pq.pop();
		}
  
		if(!tmp.empty())
		{
			ans += tmp.top(); //최대힙에서 하나 꺼내어 더함 
			tmp.pop(); //꺼낸건 pop
		}
	}

	cout<<ans<<'\n';

	return 0;
}
