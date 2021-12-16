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
	if(isDead(mafia) || cnt==1) //마피아 혼자 살아남거나, 마피아가 죽은 경우라면 반환
	{
		flag = (cnt==1); //만약, 마피아 혼자 남는다면? 다른 모든 경우는 고려하지 않음
		return 0;
	}
	
	int ret = 0;
	
	if(cnt%2) //짝수 : 낮의 경우
	{
		int g_val=-1, g_idx=-1;
		for(int i=0; i<n; i++) //최대 유죄 지수인 사람을 찾음
		{
			if(isDead(i)) continue; //이미 죽은 사람은 고려x
			if(g_val < g[i])
			{
				g_idx = i;
			   	g_val = g[i];
			}
		}
		state |= (1<<g_idx); //그 사람을 죽임
		ret = max(ret, Solve(cnt-1)); //다음 경우를 고려
		state &= ~(1<<g_idx); //백트래킹
	}

	else  //홀수 : 밤의 경우
	{
		for(int i=0; i<n; i++)
		{
			if(i==mafia || isDead(i)) continue;  //마피아 본인과, 이미 죽은사람 고려x

			state |= (1<<i); //i번째 사람을 죽임
			for(int j=0; j<n; j++) g[j] += r[i][j]; //+) 유죄 지수 갱신

			ret = max(ret, Solve(cnt-1)+1); //다음 경우를 고려

			for(int j=0; j<n; j++) g[j] -= r[i][j];
			state &= ~(1<<i);  //백트래킹
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
