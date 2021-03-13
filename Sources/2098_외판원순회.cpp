#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 16;
const int INF = 2147000000;

int n, w[MAX_N][MAX_N];
int dp[MAX_N][1<<MAX_N];
int ans = INF;

int Answer(int curr, int state) //현재 정점이 curr이고 state라는 상태일때, 최소 cost 
{
	if(state == (1<<n)-1 ) //모든 도시를 다 방문한 상태라면
	{
		if(w[curr][0]==0) return INF; //연결이 되지 않은 도시라면 INF 반환 
		return w[curr][0]; //연결이 된 도시라면, 다시 시작점으로 돌아가는 cost 반환 
	}

	int& ret = dp[curr][state]; 
	if(ret != 0) return ret;

	int tmp = INF; 
	for(int next=0; next<n; next++)
	{
        //연결이 되어있지 않거나, 이미 방문한 정점이라면
		if(w[curr][next]==0  || state & (1<<next)) continue;
        
		int nextVal = Answer(next, state | (1<<next));
		if(nextVal!=INF) //nextVal이 INF가 아니라면 tmp 갱신
			tmp = min(tmp, w[curr][next] + nextVal);
	}

	return ret = tmp;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 

	cin>>n;

	for(int i=0; i<n; i++)
	for(int j=0; j<n; j++)
		cin>>w[i][j];

	cout<<Answer(0, 1)<<'\n';

	return 0;
}
