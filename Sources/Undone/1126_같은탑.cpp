#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 50;
const int MAX_H = 500000;
const int M_INF = -2147000000;

int n, h[MAX_N], cache[MAX_N][MAX_H];

/* ----
   DP(idx, h_diff)
   : idx-1까지 선택했고, 현재 두 탑의 차이가 h_diff 일 때의 최대 높이
---- */ 
int GetAnswer(int idx, int h_diff)
{	
	if(h_diff >= MAX_H) return M_INF;
	if(idx == n) return (h_diff ? M_INF : 0);

	int &ret = cache[idx][h_diff];
	if(ret != -1) return ret;

	ret = M_INF;
	ret = max(ret, GetAnswer(idx+1, h_diff)); //idx 번째 조각을 쓰지 않음
	ret = max(ret, GetAnswer(idx+1, h_diff + h[idx])); //더 높은 탑에 배치
	
	if(h[idx] > h_diff) //더 낮은 탑에 배치
		ret = max(ret, GetAnswer(idx+1, abs(h[idx]-h_diff)) + h_diff);
	else
		ret = max(ret, GetAnswer(idx+1, abs(h[idx]-h_diff)) + h[idx]);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++)
		cin>>h[i];
	
	int ans = GetAnswer(0, 0);

	cout<<(ans ? ans : -1)<<'\n';

	return 0;
}
