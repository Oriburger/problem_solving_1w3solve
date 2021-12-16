#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<bool> visited;
vector<vector<int> > adj;
stack<int> stk;

int GetCycleCnt(stack<int> stk)
{
	int ret=0;
	int head = stk.top();
	bool isCycling = false;
	stk.pop();

	while(!stk.empty())
	{
		ret++;

		if(stk.top() == head)
		{
			isCycling = true;
			break;
		}

		stk.pop();
	}

	return isCycling ? ret : 0;
}

int DFS(int curr, const int n)
{
	int ret=0;
	visited[curr]=true;
	stk.push(curr);
	
	for(int i=0; i<adj[curr].size(); i++)
	{
		int next = adj[curr][i];
		
		if(visited[next])
		{
			stk.push(next);
			ret+=GetCycleCnt(stk);
			stk.pop();
		}
		else
			ret += DFS(next, n);
	}
	return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int t=0, n=0;
	int answer=0;

    cin>>t;

    while(t--)
    {
        cin>>n;

        visited.resize(n+1, false);
		adj.resize(n+1);

        for(int i=1; i<=n; i++)
		{
			int input;
			cin>>input;

			adj[i].push_back(input);
		}

		for(int i=1; i<=n; i++)
		{
			int val;
			if(!visited[i])
			{
				answer += DFS(i, n);
				while(!stk.empty()) //stk 초기화 
					stk.pop();
			}
			
		}
		cout<<n-answer<<'\n'; //전체 - 사이클 구성원 

		//데이터 초기화 
		answer=0;
		visited.clear(); 
		adj.clear();
    }

    return 0;
}
