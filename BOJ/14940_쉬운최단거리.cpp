#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P; 

const int dy[4] = {1, -1, 0, 0};
const int dx[4] = {0, 0, 1, -1};

int n, m; P stPos; 
int arr[1001][1001];
int dist[1001][1001];

queue<P> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin>>n>>m;
	
	memset(dist, -1, sizeof(dist)); 
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
		{
			cin>>arr[i][j];	
			if(arr[i][j] == 2) 
				stPos = {i, j};
		}

	dist[stPos.first][stPos.second] = 0;
	q.push(stPos); 

	while(!q.empty())
	{
		P curr = q.front(); 
		q.pop(); 
		
		for(int d=0; d<4; d++)
		{	
			P next = {curr.first + dy[d], curr.second + dx[d]};
			
			if(next.first < 0 || next.first >= n 
     			|| next.second < 0 || next.second >=m) continue; 
			if(dist[next.first][next.second] != -1) continue;
			if(arr[next.first][next.second] == 0) continue;			

			dist[next.first][next.second] = dist[curr.first][curr.second] + 1;
			q.push(next);
		}
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			if(arr[i][j] == 0) cout<<0<<' ';
			else if(dist[i][j]==0 && arr[i][j]!=2) cout<<-1<<' ';
			else cout<<dist[i][j]<<' ';
		}
		cout<<'\n';
	}

	return 0;
}
