#include <iostream>
using namespace std;

const int INF=2147000000;
const int cp[3]={0,1,2};
const int day[3]={1,3,5};
const int cost[3]={10000, 25000, 37000};

int n, m, arr[100];
int dp[101][101];
bool isGo[101];

//curr부터의 리조트 이용을 위한 최소비용
int GetAnswer(int curr, int cpCnt)
{
	if(curr>n) return 0;  
	int &ret = dp[curr][cpCnt];
	if(ret!=0) return ret;
	ret=INF;

	if(isGo[curr])
		return ret = GetAnswer(curr+1, cpCnt);

	for(int i=0; i<3; i++)
	{
		if(i==0 && cpCnt>=3)
			ret = min(ret, GetAnswer(curr+day[i], cpCnt-3));
		ret = min(ret, cost[i]+GetAnswer(curr+day[i], cpCnt+cp[i]));
	}

	return ret;
}

int main()
{
	cin>>n>>m;

	for(int i=0; i<m; i++)
	{
		int num; cin>>num;
		isGo[num]=true;
	}
	
	cout<<GetAnswer(1, 0)<<'\n';

	return 0;
}
