#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2147000000;
int n, h, lo=INF, hi, ans=INF, cnt;
vector<int> arr[2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>h;
	
	for(int i=0; i<n; i++)
	{
		int tmp; cin>>tmp;
		arr[i%2].push_back(tmp);
	}
	sort(arr[0].begin(), arr[0].end());
	sort(arr[1].begin(), arr[1].end());
	
	for(int i=1; i<=h; i++)
	{
		int tmp = n;
		//i 높이에서 걸리는 석순의 개수
		tmp -= lower_bound(arr[0].begin(), arr[0].end(), i) - arr[0].begin();
		//i 높이에서 걸리는 종유석의 개수
		tmp -= lower_bound(arr[1].begin(), arr[1].end(), h-i+1) - arr[1].begin();
		
		if(tmp == ans) cnt+=1;
		else if(tmp < ans)
		{
			cnt = 1;
			ans = tmp;
		}
	}
	
	cout<<ans<<' '<<cnt<<'\n';
	
	return 0;
}
