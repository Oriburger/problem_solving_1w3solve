#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int INF = 2147000000;
const int MAX_V = 10001;

unordered_map<string, int> umap; //unordered_map을 이용한 string <=> int 매칭

int v, visitCnt=1, sccCnt=0; 
vector<bool> finished(MAX_V);
vector<vector<int> > scc;
vector<int> adj[MAX_V], discovered(MAX_V), sccId(MAX_V);
vector<long long> score(MAX_V, 1); //각 정점의 점수를 저장, int의 범위를 벗어날 수 있음
stack<int> stk;

int GetValue(string key) //key에 해당하는 value를 반환
{                        //key : 문자열 형태의 사이트명,  value : 사이트명에 해당하는 정점번호
	if(umap.count(key)==0) //umap에 등록되지 않은 key라면 등록
		umap[key]=v++; 
	return umap[key];
}

int TarjanDFS(int curr) //타잔의SCC 알고리즘. 설명은 생략
{
	stk.push(curr);
	discovered[curr] = visitCnt++;

	int lowLink = discovered[curr];
	for(const int &next : adj[curr])
	{
		if(finished[next]) continue;
		if(!discovered[next])
			lowLink = min(lowLink, TarjanDFS(next));
		else
			lowLink = min(lowLink, discovered[next]);
	}

	if(lowLink == discovered[curr])
	{
		vector<int> temp;
		while(1)
		{
			int t = stk.top();
			stk.pop();
			finished[t] = true;
			sccId[t] = sccCnt;
			temp.push_back(t);

			if(t==curr) break;
		}
		scc.push_back(temp);
		sccCnt++;
	}

	return lowLink;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	
	/*=== 그래프 구성 =======*/
	for(int i=0; i<n; i++)
	{
		int k, u, v;
		string str;

		cin>>str>>k;

		v = GetValue(str);
		while(k--)
		{
			cin>>str;
			u = GetValue(str);
			adj[u].push_back(v);
		}
	}

	/*=== SCC 구성 및 점수 계산 =======*/
	for(int i=0; i<v; i++)
		if(!discovered[i])
			TarjanDFS(i); //scc 구성

	for(int i=sccCnt-1; i>=0; i--) //위상정렬 순서대로 scc를 순회
		for(auto &u : scc[i]) //scc를 구성하는 멤버들 중에
			for(auto &v : adj[u])
				if(sccId[u] != sccId[v]) //다른 scc와 연결된 정점이 있다면? 
					score[v] += score[u]; //점수를 계산!

	/*=== 정답 출력 =======*/
	string temp;
	cin>>temp;

	cout<<score[GetValue(temp)]<<'\n';
	
	return 0;
}
