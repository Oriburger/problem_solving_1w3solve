#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int d[2] = {-1, 1};
const int MAX_N = 100001;

int n, k;
vector<int> dist(MAX_N, -1);
vector<int> trace(MAX_N);

int BFS(int start)
{
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	
	while(!q.empty())
	{
		int curr = q.front();
		q.pop();
		
		if(curr == k) break;
		
		for(int i=0; i<3; i++)
		{
			int next = (i==2 ? curr * 2 : curr + d[i]);
			if(next >= MAX_N || next < 0) continue;
			if(dist[next] != -1) continue;
			
			dist[next] = dist[curr] + 1;
			trace[next] = curr;
			q.push(next);
		}
	}
	return dist[k];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>k;
	
	cout<<BFS(n)<<'\n';
	
	vector<int> route;
	int curr = k;
	while(1)
	{
		route.push_back(curr);
		if(curr==n) break;
		curr = trace[curr];
	}
	reverse(route.begin(), route.end());
	for(auto &p : route)
		cout<<p<<' ';
	cout<<'\n';
	
	return 0;
}
