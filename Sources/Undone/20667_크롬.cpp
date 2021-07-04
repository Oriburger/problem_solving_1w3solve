#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 101;
const int MAX_M = 1001;
const int MAX_P = 501;
const int INF = 2147000000;

struct info{ int cpu_usage; int mem_usage; int priority; };

int n, m, k;
int mem_usage_sum=0, cpu_usage_sum=0;
int cache[MAX_N][MAX_M][MAX_P];
vector<info> tabs(MAX_N);

int GetAnswer(int idx, int cur_usage, int priority)
{
	int &ret = cache[idx][cur_usage][priority];
	if(ret != -1) return ret;
	if(idx == n) return ret = (cpu_usage_sum - cur_usage > m ? INF : 0);

	ret = INF;

	//idx 번째 탭을 닫음
	if(priority - tabs[idx].priority >= 0)
		ret = min(ret, GetAnswer(idx+1, cur_usage + tabs[idx].cpu_usage
							, priority - tabs[idx].priority) + tabs[idx].mem_usage);
	//idx 번째 탭을 내비둠
	ret = min(ret, GetAnswer(idx+1, cur_usage, priority)); 

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m>>k;

	for(int i=0; i<n; i++)
	{
		cin>>tabs[i].cpu_usage>>tabs[i].mem_usage>>tabs[i].priority;
		mem_usage_sum += tabs[i].mem_usage;
		cpu_usage_sum += tabs[i].cpu_usage;
	}

	memset(cache, -1, sizeof(cache));
	for(int i=0; i<4; i++)
	{
		int temp = GetAnswer(0, 0, i);
		cout<<temp<<'\n';
		
		if(mem_usage_sum - temp <= k && temp != INF) break;

	//	cout<<i<<'\n';
	//	break;
	}

	return 0;
}
