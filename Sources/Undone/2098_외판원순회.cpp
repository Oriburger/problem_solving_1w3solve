#include <iostream>
#include <algorithm>

#include <vector>
using namespace std;

int n, w[17][17];
int ans = 2147000000;
vector<bool> visited;
vector<int> path;

void Answer(vector<int>& path, int total)
{
	int curr = path.back();

	if(path.size()==n)
	{
		int tmp = w[curr][path.front()];
		ans = min(ans, total + tmp);
		return;
	}

	for(int next=0; next<n; next++)
	{
		if(visited[next]) continue;
		if(w[curr][next]==0) continue;

		visited[next]=true;
		path.push_back(next);

		Answer(path, total + w[curr][next]);

		visited[next]=false;
		path.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		cin>>w[i][j];

	for(int i=0; i<n; i++)
	{
		path.clear();
		visited.clear();
		visited.resize(n, false);

		path.push_back(i);
		visited[i]=true;
		Answer(path, 0);
	}

	cout<<ans<<'\n';

	return 0;
}
