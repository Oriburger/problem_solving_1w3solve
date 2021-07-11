#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_N = 50;
const int MAX_H = 500000;
const int INF = 2147000000;

int n;
vector<int> h;
vector<vector<int> > cache;

/*
int GetAnswer(int idx, int c1)
{	
	int &ret = cache[idx][c1];

	if(ret != -1) return ret;
	if(idx == n) return 0;

	ret = GetAnswer(idx+1, c1+h[idx]);
	ret = max(ret, GetAnswer(idx+1, c1)+h[idx]);
	ret = max(ret, GetAnswer(idx+1, c1));

	return ret;
}*/

/*
	#1 ---
	cache[idx][h] : idx-1까지 모두 선택이 끝났고, colA의 높이가 h일때,
					두 기둥의 높이를 같게하여 얻을 수 있는 높이의 최대 (X)
	#2 ---
	cache[idx][h] : idx-1까지 모두 선택이 끝났고, colA의 높이가 h일때,
					두 기둥의 높이를 같게 할 수 있는지 여부  (X)
	#3 ---
	cache[idx][h] : idx-1까지 모두 선택이 끝났고, colA의 높이가 h일때,
					colA와 차이가 최소가 되는 colB의 높이
	#4 ---
	cache[idx][h] : idx-1까지 모두 선택이 끝났고, colA의 높이가 h일때,
					colB와 높이 차이의 최소
	#5 ---
	
*/

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	h = vector<int>(n, 0);
	cache = vector<vector<int> >(n, vector<int>(MAX_H, INF));

	for(int i=0; i<n; i++)
		cin>>h[i];
	
	sort(h.begin(), h.end());

	cache[0][h[0]] = 0;
	cache[0][0] = h[0];
	for(int i=1; i<n; i++)
	{
		for(int j=0; j<MAX_H; j++)
			if(cache[i-1][j]!=INF)
			{
				cache[i][j] = cache[i-1][j]; //i번째를 사용하지 않음
				int tmp = abs(j - cache[i][j]);

				if(j + h[i-1] < MAX_H && 
						tmp > abs(j+h[i-1] - cache[i-1][j]))
					cache[i][j] = cache[i-1][j + h[i-1]]; //A에 쌓음

				if(tmp > abs(j - cache[i-1][j] + h[i-1]))
					cache[i][j] = cache[i-1][j] + h[i-1];//B에 쌓음
			}
	}

	int ans=-1;
	for(int i=0; i<11; i++)
	{
		cout<<i<<") "<<cache[n-1][i]<<'\n';
	}
		//if(cache[n-1][i] == i)	
			//ans = max(ans, cache[n-1][i]);
	
	//cout<<ans<<'\n';

	return 0;
}
