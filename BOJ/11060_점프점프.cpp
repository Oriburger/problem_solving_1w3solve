#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n, ans=-1, arr[1001];
bool visited[1001];
queue<P> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	for(int i=0; i<n; i++)
	    cin>>arr[i];
	   
	q.push({0, 0});
	visited[0] = true;
	while(!q.empty())
	{
		int curr = q.front().first;
		int cur_dist = q.front().second;
		q.pop();
		
		if(curr == n-1)
		{
			ans = cur_dist;
			break;
		}
		
		for(int i=1; i<=arr[curr]; i++)
		{
			int next = curr+i;
			
			if(next >= n || visited[next]) continue;
			
			q.push({next, cur_dist+1});
		        visited[next]=true;
                }
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
