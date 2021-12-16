#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
private:
	int n; //����� ���� 
	
	int head; //stack���� �ߺ��Ǵ� ���� head 
	bool flag; //cycle ���� ��尡 ����Ǳ� ���� ���� flag 
	vector<bool> chkCycling; //cycle Ž���� ���� visited�� ���еǴ� üũ array 
	
	vector<vector<int> > adj; //��������Ʈ ��� �׷��� 
	vector<bool> visited; //�湮 üũ array
	vector<int> ans; //���� array
	
public:
	//�����ڸ� Ȱ����  �ʱ�ȭ 
	Graph(int num) : n(num), head(0), flag(false)
	{
		adj.resize(n+1);	
		visited.resize(n+1);
		chkCycling.resize(n+1);
	}
	
	//��������Ʈ addEdge 
	void addEdge(int u, int v)
	{
		adj[u].push_back(v);
	}
	
	//Ž�� 
	void DFS(int curr)
	{
		if(visited[curr])
			return;
		
		visited[curr] = true;
		chkCycling[curr] = true;
		
		for(int i=0; i<adj[curr].size(); i++)
		{
			int next = adj[curr][i];
			
			//�湮�� ����̰�, �̹� DFSŽ������ �湮�� ����� ���
			//��, stack���� cycleŽ�� ���� ���� ���Ե� ��� && �湮�� ����� ��� 
			if(visited[next] && chkCycling[next])
			{
				flag=false; 
				head = next;
			}
			
			DFS(next);
		}
		
		if(!flag) //ans array�� push 
		{
			ans.push_back(curr);
			
			//stack�� Ǫ�� �������� head ���� �ٽ� ������ ���,
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
	
	//�ش� node�� ���� Ž���� ����Ǿ�����,
	//cycle Ž���� ���� ����� stack ������ ���� ������ �ٲ��ش�.
	//Ž������ �湮��带 chkCycling�� üũ 
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
					                   
	Graph g(n); //Graph ���� �� Initialize 
	
	for(int i=1; i<=n; i++)
	{         
		int input;
		cin>>input;
		
		g.addEdge(i, input);
	}
	
	for(int i=1; i<=n; i++)
	{
		g.DFS(i);
		g.ResetState(); //stack ���� �缳�� 
	}
	
	g.PrtAnswer();
		 
	return 0;
}
