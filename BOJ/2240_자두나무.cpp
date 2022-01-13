#include <bits/stdc++.h>
using namespace std;

int t, w;
int cache[1000][2][31];
vector<int> arr;


//	f[t][pos][w] = { t 초에 자두가 w에 서 있고 w번 더 움직일 수 있을 때, 먹을 수 있는 최대의 자두 개수}

int GetAnswer(int curr, int k, int remain)
{
	if(curr >= t) return 0;
	int &ret = cache[curr][k][remain];
	if(ret != -1) return ret;

	ret = (arr[curr]==(k+1));

	if(remain > 0)
		ret += max(GetAnswer(curr+1, k, remain), GetAnswer(curr+1, !k, remain-1));
	else 
		ret += GetAnswer(curr+1, k, remain);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t>>w;

	arr = vector<int>(t);
	for(int i=0; i<t; i++)
		cin>>arr[i];

	memset(cache, -1, sizeof(cache));

	cout<<max(GetAnswer(0, 0, w), GetAnswer(0, 1, w-1))<<'\n';

	return 0;
}
