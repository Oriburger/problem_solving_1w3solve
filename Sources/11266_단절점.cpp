#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 100002;
typedef pair<int, int> P;

int v, e, visitCnt=1;
vector<int> adj[MAX], discovered(MAX, 0);
vector<bool> isCutVertex(MAX, false);

//curr을 루트로 하는 서브트리에 있는 단절점을 도출
//반환값? - 해당 서버트리에서 역방향 간선으로 갈 수 있는 정점 중
//가장 일찍 발견된 정점의 발견 시점. 첫 호출 시 -> isRoot는 true
int DFS(int curr, bool isRoot)
{
	//발견순서 기록
	discovered[curr] = visitCnt++;
	int ret = discovered[curr];

	//자손 서브트리의 개수 저장
	//루트일 경우의 단절점 판정 위함.
	int children = 0; 

	for(auto &next : adj[curr])
	{
		if(!discovered[next])
		{
			children++;
			//이 서브트리에서 갈 수 있는 가장 높은 정점의 번호
			int subtree = DFS(next, false);
			//그 노드가 자기 자신 이하에 있다면, 현재 정점은 단절점
			if(!isRoot && subtree >= discovered[curr])
				isCutVertex[curr]=true;
			ret = min(ret, subtree);
		}
		else
			ret = min(ret, discovered[next]);
	}
	//루트인 경우에 단절점 판정은 서브트리의 개수로 함.
	if(isRoot && children >= 2) isCutVertex[curr]=true;
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
			DFS(i, true);

	int cnt=0;
	vector<int> ans;
	for(int i=1; i<=v; i++)
		if(isCutVertex[i])
		{
			cnt++;
			ans.push_back(i);
		}
	
	cout<<cnt<<'\n';
	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
