#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 201;
const int INF = 2147000000;

int n, k;
vector<int> arr;
int cache[MAX_N][MAX_N];

//L번째 전구부터 R번째 전구까지 색을 통일 시키는데 드는 최소 변경횟수
int GetAnswer(int l, int r)
{
	if(l >= r) return 0;

	int &ret = cache[l][r];
	if(ret != -1) return ret;

	ret = INF;
	for(int i=l; i<r; i++)
	{
		int w = (arr[l]==arr[i+1] ? 0 : 1);
		ret = min(ret, GetAnswer(l, i) + GetAnswer(i+1, r) + w);
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	arr = vector<int>(n, 0);
	memset(cache, -1, sizeof(cache));

	for(int i=0; i<n; i++)
		cin>>arr[i];

	cout<<GetAnswer(0, n-1)<<'\n';

	return 0;
}
