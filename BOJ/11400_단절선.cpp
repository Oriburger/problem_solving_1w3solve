#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 100002;
typedef pair<int, int> P;

int v, e, visitCnt=1;
vector<int> adj[MAX], discovered(MAX, 0);
vector<P> cutEdge;

//현재의 정점과 부모 정점을 매개변수로 사용한다.
int DFS(int curr, int parent)
{
	//발견순서 기록
	discovered[curr] = visitCnt++;
	int ret = discovered[curr];

	for(auto &next : adj[curr])
	{
		//다시 부모 정점으로 올라가는 간선은 continue;
		if(next == parent) continue;

		//아직 방문하지 않은 간선을 기준으로 찾는다.
		if(!discovered[next])
		{
			//이 서브트리에서 갈 수 있는 가장 높은(level이 가장 작은) 정점의 번호
			int lowPoint = DFS(next, curr);
			//curr보다 더 높은(level이 더 낮은) 간선에 도달이 불가능하다면, 단절선
			if(lowPoint > discovered[curr])
			{
				if(curr > next) cutEdge.push_back({next, curr});
				else cutEdge.push_back({curr, next});
			}
			ret = min(ret, lowPoint);
		}
		else
			ret = min(ret, discovered[next]);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>v>>e;
	for(int i=0; i<e; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=1; i<=v; i++)
		if(!discovered[i])
			DFS(i, 0);

	sort(cutEdge.begin(), cutEdge.end());
	
	cout<<cutEdge.size()<<'\n';
	for(const P &p : cutEdge)
		cout<<p.first<<' '<<p.second<<'\n';

	return 0;
}
