#include <bits/stdc++.h>
using namespace std;

const int INF = 100999;

int n;
int cache[2001][2001];

//k를 0으로 만드는 방법의 수 (마지막으로 사용한 수가 curr)
int GetAnswer(int k, int curr)
{
	if(k==0) return 1; //기저사례 : 0을 만들 수 있다면, 방법을 하나 찾음

	int &ret = cache[k][curr];
	if(ret != 0) return ret; //메모이제이션

	for(int i=curr+1; i<=k; i++) //중복 사용 방지 : 마지막으로 사용한 수+1 ~ k를 이용 
		ret = (GetAnswer(k-i, i)+ret)%INF;

	return ret%INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin>>t;

	while(t--)
	{
		cin>>n;
		cout<<GetAnswer(n, 0)<<'\n';
	}

	return 0;
}
