#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

ull n, s, threshold, ans, sum;
vector<ull> arr;
map<ull, ull> cnt;

void DFS(int curr, bool bIsThreshold)
{
	if(curr == (bIsThreshold ? n : threshold))
	{
		if(!bIsThreshold) //시작점 ~ 중간지점
		{
			auto iter = cnt.find(sum); //합이 sum이 되는 수를 찾음
			if(iter != cnt.end()) (iter->second) += 1; //있다면 개수를 더함
			else cnt[sum] = 1; //없다면 map에 추가
		}
		else //도착점~중간지점
		{
			auto iter = cnt.find(s-sum); //합이 s-sum이 되는 수를 찾음
			if(iter != cnt.end()) ans += iter->second; //있다면 정답 갱신
		}
		return;
	}
	DFS(curr+1, bIsThreshold); //curr을 pick하지 않음
	sum += arr[curr];
	DFS(curr+1, bIsThreshold); //curr을 pick
	sum -= arr[curr]; //backtrack
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>s;

	arr = vector<ull>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	threshold = n/2; //절반으로 나눔

	DFS(0, false); //[0 ~ threshold-1] 탐색
	DFS(threshold, true); //[threshold ~ n-1] 탐색

	if(s==0) ans-=1; //아예 고르지 않는 상황은 제외 
	cout<<ans<<'\n';

	return 0;
}
