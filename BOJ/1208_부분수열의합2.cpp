#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, s, tmp, ans;
vector<ll> arr;
unordered_map<int, int> umap;

void DFS(int curr, bool bIsThreshold)
{
	if(curr == (!bIsThreshold ? n/2 : n))
	{
		if(!bIsThreshold) //시작점 ~ 중간지점
		{
			if(umap.count(tmp)==0) umap[tmp] = 1; //합이 tmp가 되는 수를 찾음
			else umap[tmp] += 1; //있다면 개수를 더함
		}
		else //도착점~중간지점
		{
			if(umap.count(s - tmp)!=0)  //합이 s-tmp가 되는 수를 찾음
				ans += umap[s-tmp]; //있다면 정답 갱신
		}
		return; 
	}
	DFS(curr+1, bIsThreshold); //curr을 pick하지 않음
	tmp += arr[curr];
	DFS(curr+1, bIsThreshold); //curr을 pick
	tmp -= arr[curr]; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>s;

	arr = vector<ll>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	DFS(0, false);  //[0 ~ threshold-1] 탐색
	DFS(n/2, true);  //[threshold ~ n-1] 탐색

	if(s==0) ans-=1 ; //아예 고르지 않는 상황은 제외 
	cout<<ans<<'\n';

	return 0;
}
