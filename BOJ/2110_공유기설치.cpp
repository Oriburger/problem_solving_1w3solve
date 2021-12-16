#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c;
vector<int> pos;

//해당 조건에서 설치가 가능한가?
bool CanInstall(const int d)
{
	int cnt=1, temp=0;
	for(int i=1; i<n; i++)
	{		
		if(pos[i]-pos[i-1]+temp >= d)
		{
			cnt++;
			temp=0;
		}
		else
			temp+=(pos[i]-pos[i-1]);
	}

	return cnt >= c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>c;

	pos.resize(n, 0);
	for(int i=0; i<n; i++)
		cin>>pos[i];
	
	sort(pos.begin(), pos.end()); //정렬.

	//lo는 최소간격, hi는 최대간격
	int lo=1, hi=pos[n-1]-pos[0];
	int mid, ans=0;
	while(lo<=hi)
	{
		mid = (lo+hi)/2;

		if(CanInstall(mid)) //설치가 가능하다면? 
		{
			ans = max(ans, mid); //답 갱신
			lo = mid + 1; //lo 갱신
		}
		else hi=mid-1; //그렇지 않다면 hi갱신 
	}

	cout<<ans<<'\n';

	return 0;
}
