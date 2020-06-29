#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2147000000;

int n, s[21][21], answer=INF;
vector<int> c;

int GetTeamStat(const int flag)
{
	int ret = 0;
	vector<int> team;
	
	for(int i=0; i<n; i++)
		if(c[i]==flag) team.push_back(i);

	for(int i=0; i<team.size(); i++)
		for(int j=i+1; j<team.size(); j++)
			ret += s[team[i]][team[j]] + s[team[j]][team[i]];
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		c.push_back(i>=n/2 ? 1 : 0);
		for(int j=0; j<n; j++)
			cin>>s[i][j];
	}
	
	do
	{
		int statA=0, statB=0;
		
		statA = GetTeamStat(0);
		statB = GetTeamStat(1);
		
		answer = min(answer, abs(statA-statB));
		
	}while(next_permutation(c.begin(), c.end()));
	
	cout<<answer<<'\n'; 
	
	return 0;
}
