#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <set>
using namespace std;

typedef pair<int, int> P;

const char cmd[4] = {'D','S','L','R'};

int DFunc(int n){ return n*2 > 9999 ? n*2%10000 : n*2; }
int SFunc(int n){ return n-1 == 0 ? 9999 : n-1; }
int LRFunc(int n, const char dir)
{
	int temp;

	if(dir == 'L')
	{
		temp = n/1000;
		return (n-temp*1000)*10+temp;
	}
	else if(dir == 'R')
	{
		temp = n%10;
		return n/10+temp*1000;
	}

	return 0;
}

int BFS(int start, int end)
{
	queue<P> q;
	vector<pair<P, int> > path;
	set<int> visited;
	q.push({start, -1});
	visited.insert(start);

	while(!q.empty())
	{
		P curr = q.front();
		q.pop();

		//cout<<curr.first<<',';

		if(curr.first == end)
		{
			int end = curr.first;
			int prev = path[path.size()-2].second;

			//cout<<end<<' '<<prev<<'\n';
			
			for(int i=path.size()-1; i>=0; i--)
				cout<<path[i].second<<' ';
			

			return 0;
		}

		for(int i=0; i<4; i++)
		{
			P next;

			if(i==0) next = { DFunc(curr.first), 0 };
			else if(i==1) next = { SFunc(curr.first), 1};
			else if(i==2) next = { LRFunc(curr.first, 'L'), 2};
			else if(i==3) next = { LRFunc(curr.first, 'R'), 3};

			if(visited.count(next.first)!=0) continue;

			visited.insert(next.first);
			q.push(next);
			path.push_back({next, curr.first});
		}
	}
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t; cin>>t;

	while(t--)
	{
		int a, b;

		cin>>a>>b;

		BFS(a, b);
	}

	return 0;
}
