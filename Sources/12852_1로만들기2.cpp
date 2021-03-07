#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
const int MAX = 10000001;
vector<bool> visited(MAX, 0);
vector<int> parent(MAX, -1);

void Answer(int k)
{
	queue<int> q;
	q.push(k);
	visited[k]=true;
	parent[k]=k;

	while(!q.empty())
	{
		int curr = q.front();
		q.pop();

		if(curr==1) break;

		if(curr%3==0 && !visited[curr/3])
		{
			q.push(curr/3);
			visited[curr/3]=true;
			parent[curr/3]=curr;
		}

		if(curr%2==0 && !visited[curr/2])
		{
			q.push(curr/2);
			visited[curr/2]=true;
			parent[curr/2]=curr;
		}

		if(!visited[curr-1])
		{
			q.push(curr-1);
			visited[curr-1]=true;
			parent[curr-1]=curr;
		}
	}

	int curr = 1;
	vector<int> ans;

	while(1)
	{
		ans.push_back(curr);
		if(curr == parent[curr]) break;
		curr = parent[curr];
	}

	reverse(ans.begin(), ans.end());
	cout<<ans.size()-1<<'\n';
	for(auto &p : ans)
		cout<<p<<' ';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	Answer(n);

	return 0;
}
