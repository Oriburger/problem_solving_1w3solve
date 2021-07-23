#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 10001;

int n, trace[MAX_N]; //집합 실제 해 출력을 위한 배열
int cache[MAX_N][2]; //캐싱
vector<vector<int> > adj; //트리 인접리스트
vector<int> w; //각 정점의 가중치

//현재 curr이고, 부모는 prev, 현재의 노드가 isMember일 때
//계속 DFS 탐색을 해서 얻을 수 있는 (최대-독립-집합 멤버들의)최대 가중치 합
int DFS(int curr, int prev, bool isMember)
{
	int &ret = cache[curr][isMember];

	if(ret != -1) return ret;

	ret = (isMember ? w[curr] : 0);
	for(auto &next : adj[curr])
	{
		if(next == prev) continue; //부모로 다시 올라가지 않게 처리
		
		int tmp1 = -1, tmp2 = -1;
		if(!isMember) tmp1 = DFS(next, curr, true);
		tmp2 = DFS(next, curr, false);

		ret += max(tmp1, tmp2);
	}

	return ret;
}

//실제 정답 출력을 위한 함수
void GetAnswer(int curr, int prev)
{
    	//이전 노드가 멤버가 아니고, 이번 노드가 멤버일때의 DP해가 더 크다면?
	if(!trace[prev]  &&  cache[curr][true] > cache[curr][false])
		trace[curr] = true; //이번 노드는 멤버임

    	//트리 DFS탐색
	for(auto &next : adj[curr])
	{
		if(next == prev) continue; //부모로 올라가지 않음
		GetAnswer(next, curr); 
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	adj.resize(n+1);
	w.resize(n+1, 0);
	memset(cache, -1, sizeof(cache));

	for(int i=1; i<=n; i++)
		cin>>w[i];

	for(int i=0; i<n-1; i++)
	{
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int tmp1, tmp2;
	tmp1 = DFS(1, 0, true); //1번 노드가 멤버일때의 해
	tmp2 = DFS(1, 0, false); //멤버가 아닐때의 해 
	cout<<max(tmp1, tmp2)<<'\n'; //두 경우 중에서 최댓값 출력
	
	GetAnswer(1, 0); //실제 해 탐색
	for(int i=1; i<=n; i++) 
		if(trace[i]) cout<<i<<' '; //멤버라면 idx 출력

	return 0;
}
