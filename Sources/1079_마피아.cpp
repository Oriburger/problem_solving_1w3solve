#include <bits/stdc++.h>
using namespace std;

int n, mafia, state = (1<<17);
bool flag = false;

vector<int> g;
vector<vector<int> > r;

int Solve(int idx, int state, int cnt);

inline bool isDead(int idx)
{
	if(state & (1<<idx)) return true;
	return false;
}

int Solve(int cnt)
{
	if(flag) return 0;
	if(isDead(mafia) || cnt==1)
	{
		flag = (cnt==1);
		return 0;
	}
	
	int ret = 0;
	
	if(cnt%2) //짝수 : 낮
	{
		int g_val=-1, g_idx=-1;
		for(int i=0; i<n; i++)
		{
			if(isDead(i)) continue;
			if(g_val < g[i])
			{
				g_idx = i;
			    g_val = g[i];
			}
		}
		state |= (1<<g_idx);
		ret = max(ret, Solve(cnt-1));
		state &= ~(1<<g_idx);
	}

	else 
	{
		for(int i=0; i<n; i++)
		{
			if(i==mafia || isDead(i)) continue;

			state |= (1<<i);
			for(int j=0; j<n; j++) g[j] += r[i][j];

			ret = max(ret, Solve(cnt-1)+1);

			state &= ~(1<<i);
			for(int j=0; j<n; j++) g[j] -= r[i][j];
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
	r = vector<vector<int> >(n+1, vector<int>(n, 0));

	for(int i=0; i<n; i++)
		cin>>g[i];

	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			cin>>r[i][j];

	cin>>mafia;

	cout<<Solve(n)<<'\n';

	return 0;
}
