/*
동서남북은 페이크, 육각형으로 고정이기에 꺾인 부분이 없는 두 변을 찾기만 하면 됨
하나씩 피봇으로 잡고, 2개 4개 쌍을 지으며 합이 같은 부분을 찾으면 됨
그리고 피봇 변으로 전체 넓이 구하고, 작은 부분 넓이 빼주면 끝
*/

#include <bits/stdc++.h>
using namespace std;

int k, ans = 0; 
vector<int> arr = vector<int>(6, 0);

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>k;
	for(int i=5; i>=0; i--)
		cin>>arr[i]>>arr[i];

	for(int i=0; i<6; i++)
	{
		int sum[2] = {0, 0};
		for(int j=0; j<6; j++)
		{
			sum[j<2] += arr[(i+j)%6];
		}
		if(sum[0] == sum[1])
		{
			ans = arr[i] * arr[(i+1) % 6] - arr[(i+3) % 6] * arr[(i+4) % 6];
			ans *= k;
			break;
		}
	}
	cout<<ans<<'\n';
	
	return 0;
}
