#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 101;
const int MAX_P = 501;
const int MAX_M = 1001;
const int INF = 2147000000;

struct Info{ int c; int m; int p; };

int N, M, K;
int cache[MAX_N][MAX_M][MAX_P];
vector<Info> tabs;

int GetAnswer(int idx, int c_sum, int p)
{
	int &ret = cache[idx][c_sum][p];
	if(ret != -1) return ret;
	if(idx == N) return ret = c_sum < M ? -INF : 0;

	ret = -INF;
	//tab[idx]를 닫음
	if(p - tabs[idx].p >= 0)
	{
		int next_c = min(c_sum + tabs[idx].c, MAX_M-1);
		ret = max(ret, GetAnswer(idx+1, next_c, p-tabs[idx].p) + tabs[idx].m);
	}
	//tab[idx]를 닫지 않음
	ret = max(ret, GetAnswer(idx+1, c_sum, p));

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>N>>M>>K;

	tabs.resize(N);
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<N; i++)
		cin>>tabs[i].c>>tabs[i].m>>tabs[i].p;
	
	int answer = -1;
	for(int i=0; i<MAX_M; i++)
	{
		int temp = GetAnswer(0, 0, i);
		if(temp < K || temp == -INF) continue;

		answer = i;
		break;
	}

	cout<<answer<<'\n';

	return 0;
}
