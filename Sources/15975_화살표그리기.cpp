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
		
		if(adj[curr].size()==1) break;
			
		else if(adj[curr].size()==2)
			answer += 2*abs(adj[curr][0] - adj[curr][1]);
		
		else if(adj[curr].size()>=3)
			for(int j=0; j<adj[curr].size(); j++)
			{
				if(j==0)
					answer += abs(adj[curr][j+1] - adj[curr][j]);
				else if(j==adj[curr].size()-1)
					answer += abs(adj[curr][j] - adj[curr][j-1]);
				else
					answer += min(abs(adj[curr][j+1]-adj[curr][j]),
								  abs(adj[curr][j]-adj[curr][j-1]));
			}
	}
	
	cout<<answer<<'\n';
	
	return 0;
}
