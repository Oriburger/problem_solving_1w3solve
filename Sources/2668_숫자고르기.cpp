#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private:
	int n; //노드의 개수 
	
	int head; //stack에서 중복되는 값이 head 
	bool flag; //cycle 구성 노드가 저장되기 위한 구분 flag 
	vector<bool> chkCycling; //cycle 탐색을 위해 visited와 구분되는 체크 array 
	
	vector<vector<int> > adj; //인접리스트 기반 그래프 
	vector<bool> visited; //방문 체크 array
	vector<int> ans; //정답 array
	
public:
	//생성자를 활용한  초기화 
	Graph(int num) : n(num), head(0), flag(false)
	{
		adj.resize(n+1);	
		visited.resize(n+1);
		chkCycling.resize(n+1);
	}
	
	//인접리스트 addEdge 
	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
	}
	
	//탐색 
	void DFS(int curr)
	{
		if(visited[curr])
			return;
		
		visited[curr] = true;
		chkCycling[curr] = true;
		
		for(int i=0; i<adj[curr].size(); i++)
		{
			int next = adj[curr][i];
			
			//방문한 노드이고, 이번 DFS탐색에서 방문한 노드일 경우
			//즉, stack에서 cycle탐색 범위 내에 포함될 경우 && 방문한 노드인 경우 
			if(visited[next] && chkCycling[next])
			{
				flag=false; 
				head = next;
			}
			
			DFS(next);
		}
		
		if(!flag) //ans array에 push 
		{
			ans.push_back(curr);
			
			//stack을 푸는 과정에서 head 값을 다시 만났을 경우,
			if(head == curr)  
				flag = true;
				
			return;
		}
		
		return;
	}
	
	void PrtAnswer()
	{
		sort(ans.begin(),ans.end());
		
		cout<<ans.size()<<'\n';
		for(int i=0; i<ans.size(); i++)
			cout<<ans[i]<<'\n';
	}
	
	//해당 node에 대한 탐색이 종료되었을때,
	//cycle 탐색을 위해 명시적 stack 내부의 시작 지점을 바꿔준다.
	//탐색마다 방문노드를 chkCycling에 체크 
	void ResetState()
	{
		chkCycling.assign(n+1, false); 
	}
	
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n=0;
	cin>>n; 
					                   
	Graph g(n); //Graph 선언 및 Initialize 
	
	for(int i=1; i<=n; i++)
	{         
		int input;
		cin>>input;
		
		g.addEdge(i, input);
	}
	
	for(int i=1; i<=n; i++)
	{
		g.DFS(i);
		g.ResetState(); //stack 범위 재설정 
	}
	
	g.PrtAnswer();
		 
	return 0;
}
