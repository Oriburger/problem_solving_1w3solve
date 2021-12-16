#include <bits/stdc++.h>
using namespace std;

int n, k;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	int lo = 1, hi = k; //정답은 k보다 클 수 없음
	while(lo <= hi) //이분 탐색
	{
		const int mid = (lo+hi)/2;
	
		int tmp=0; //2차원 배열에서 mid보다 작거나 같은 수의 개수
		for(int i=1; i<=n; i++) //i번째 행에서의
			tmp += min(mid/i, n); //작거나 같은 수들을 모두 세어줌

		if(tmp >= k) hi = mid - 1; //범위를 좁힘
		else lo = mid + 1; //범위를 좁힘
	}

	cout<<lo<<'\n';

	return 0;
}
