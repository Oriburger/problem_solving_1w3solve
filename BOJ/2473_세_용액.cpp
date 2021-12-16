#include <bits/stdc++.h>
using namespace std;

long long n, min_diff = 3000000001;
vector<long long> arr, ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	
	arr = vector<long long>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	sort(arr.begin(), arr.end()); //입력을 오름차순 정렬

	for(int lo = 0; lo < arr.size()-2; lo++) //lo를 기준으로 잡아둠
	{
		int mid = lo+1; 
		int hi = arr.size()-1; // [lo+1 ~ arr.size()-1] 구간에서 정답 탐색

		while(mid < hi) //투 포인터 탐색
		{
			long long temp = arr[lo]+arr[mid]+arr[hi];

			if(abs(temp) < min_diff) //정답을 찾았다면? 
			{
				min_diff = abs(temp);
				ans = {arr[lo], arr[mid], arr[hi]};
			}
			if(temp < 0) mid++; //음수라면 mid를 증가해서 0에 더 가까운 답을 찾는걸 꾀함
			else if(temp > 0) hi--; //양수라면 반대
			else break; //0이면 이미 가능한 가장 최적의 해
		}
	}
	cout<<ans[0]<<' '<<ans[1]<<' '<<ans[2]<<'\n';

	return 0;
}
