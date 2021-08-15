#include <bits/stdc++.h>
using namespace std;

bool flag = 0;
int n, mafia;
vector<int> g;
vector<bool> dead;
vector<vector<int> > r;

int Solve(int cnt)
{
	if(flag) return 0;
	if(cnt==1 || dead[mafia])
	{
		flag = (cnt==1);
		return 0;
	}

	int ret = 0;
	if(cnt%2) //짝수 : 낮
	{
		int g_val = -1, g_idx=-1;
		for(int i=0; i<n; i++)
		{
			if(dead[i]) continue;
			if(g_val < g[i])
			{
				g_idx = i;
			    g_val = g[i];
			}
		}

		dead[g_idx] = true;
		ret = max(ret, Solve(cnt-1));
		dead[g_idx] = false;
	}

	else //홀수 : 밤
	{
		//cout<<"Night\n";
		for(int i=0; i<n; i++)
		{
			if(i==mafia || dead[i]) continue;

			dead[i] = true;
			for(int j=0; j<n; j++) g[j] += r[i][j];
			
			ret = max(ret, Solve(cnt-1)+1);
			
			for(int j=0; j<n; j++) g[j] -= r[i][j];
			dead[i] = false;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	g = vector<int>(n, 0);
	dead = vector<bool>(n, 0);
	r = vector<vector<int> >(n, vector<int>(n, 0));

	for(int i=0; i<n; i++)
		cin>>g[i];

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>r[i][j];

	cin>>mafia;

	cout<<Solve(n)<<'\n';

	return 0;
}
