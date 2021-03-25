#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 101;

int n, m;
int sum;
int mem[MAX], cost[MAX];
int cache[MAX*100][MAX];

//남은 cost가 sum이고, idx 이후의 앱을 비활성화 시켰을때의 메모리 합
int Answer(int sum, int idx)
{
	if(idx==n) return 0;

	int &ret = cache[sum][idx];
	if(ret != -1) return ret;

	ret = Answer(sum, idx+1);

	if(cost[idx] <= sum)
		ret = max(ret, Answer(sum - cost[idx], idx+1) + mem[idx]);

	return ret;
}	

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;

	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++) cin>>mem[i];
	for(int i=0; i<n; i++) cin>>cost[i];
	
	int ans = 0;
	while(1)
	{
		//비활성화 할 수 있는 앱의 cost합이 ans일 때,
		//m 이상의 메모리를 확보 할 수 있다면? 정답 출력
		if(Answer(ans, 0) >= m)
		{
			cout<<ans<<'\n';
			return 0;
		}
		ans+=1;
	}

	return 0;
}
