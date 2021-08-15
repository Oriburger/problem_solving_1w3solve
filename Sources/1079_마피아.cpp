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
	if(cnt==1 || dead[mafia]) //마피아 혼자 살아남거나, 마피아가 죽은 경우라면 반환
	{
		flag = (cnt==1); //만약, 마피아 혼자 남는다면? 다른 모든 경우는 고려하지 않음
		return 0;
	}

	int ret = 0;
	if(cnt%2) //짝수 : 낮의 경우
	{
		int g_val = -1, g_idx=-1;
		for(int i=0; i<n; i++) //최대 유죄 지수인 사람을 찾음
		{
			if(dead[i]) continue; //이미 죽은 사람은 고려x
			if(g_val < g[i])
			{
				g_idx = i;
			    g_val = g[i];
			}
		}

		dead[g_idx] = true; //그 사람을 죽임
		ret = max(ret, Solve(cnt-1)); //다음 경우를 고려
		dead[g_idx] = false; //백트래킹
	}

	else //홀수 : 밤의 경우
	{
		for(int i=0; i<n; i++)
		{
			if(i==mafia || dead[i]) continue; //마피아 본인과, 이미 죽은사람 고려x

			dead[i] = true; //i번째 사람을 죽임
			for(int j=0; j<n; j++) g[j] += r[i][j]; //유죄 지수 갱신
			
			ret = max(ret, Solve(cnt-1)+1); //다음 경우를 고려
			
			for(int j=0; j<n; j++) g[j] -= r[i][j]; //백트래킹
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
