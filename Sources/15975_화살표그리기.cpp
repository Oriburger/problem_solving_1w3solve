#include <iostream> 
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

int n;
unsigned long long answer;
vector<vector<int> > adj;
vector<int> posArr;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	adj.resize(100001);
	for(int i=0; i<n; i++)
	{
		int p, c;
		cin>>p>>c;
		
		posArr.push_back(c);
		adj[c].push_back(p);
	}
	
	sort(posArr.begin(), posArr.end());
	posArr.erase(unique(posArr.begin(), posArr.end()), posArr.end());
	
	for(int i=0; i<posArr.size(); i++)
		sort(adj[posArr[i]].begin(), adj[posArr[i]].end());
	
	for(int i=0; i<posArr.size(); i++)
	{
		int curr = posArr[i];
		
		if(adj[curr].size() < 2) continue;

		for(int j=0; j<adj[curr].size(); j++)
		{
			if(j==adj[curr].size()-1)
				answer+=adj[curr][j] - adj[curr][j-1];
			else if(j==0)
				answer+=adj[curr][j+1] - adj[curr][j]; 
			else
				answer += min(adj[curr][j]-adj[curr][j-1], 
								adj[curr][j+1]-adj[curr][j]);
		}
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
