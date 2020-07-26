#include <iostream>
#include <vector>
#include <algorithm> 
#include <utility>
#include <queue>
#define INF 2147000000
using namespace std;

vector<bool> sieve(1000001, false);
vector<int> dp(1000001, -1), pnum;

int Answer(int start, const int a, const int b)
{
	queue<pair<int, int> > q;
	vector<bool> visited(1000001, false);
	q.push({start, 0});
	visited[start]=true;
	
	while(!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();
		
		if(curr.first >= a && curr.first <=b
			 && !sieve[curr.first])
				return curr.second;
		
		for(int i=0; i<4; i++)
		{
			int next = 0;
			
			if(i==0) next = curr.first/3;
			else if(i==1) next = curr.first/2;
			else if(i==2) next = curr.first-1;
			else next = curr.first+1;
			
			if(next <= 0) continue;
			if(visited[next]) continue;
			
			q.push({next, curr.second+1});
			visited[next]=true;
		}
	}
	
	return INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int t; cin>>t;

	sieve[1]=true;
	for(int i=2; i<1000001;i++)
	for(int j=2; i*j<1000001; j++)
		sieve[i*j]=true;
	
	for(int i=2; i<1000001;i++)
		if(!sieve[i]) pnum.push_back(i);
	
	while(t--)
	{
		int n, a, b, ans=INF;
		cin>>n>>a>>b;
	
		if(*(lower_bound(pnum.begin(), pnum.end(), a)) <= b)
			cout<<Answer(n, a, b)<<'\n';
		else
			cout<<-1<<'\n';
		
		dp.clear();
		dp.resize(1000000, -1);
	}
	
	return 0;
}
