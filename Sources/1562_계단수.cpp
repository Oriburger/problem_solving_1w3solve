#include <iostream>
#include <vector>
using namespace std;

const int MAX = 10;
const int INF = 1000000000;
const int d[2] = {-1, 1};

int cache[101][MAX][(1<<MAX)];
int ans = INF;

int Answer(int k, int curr, int state)
{
	if(k==0)
	{
		if(state!=(1<<(MAX+1))-1) return -1;
		return 1;
	}

	int &ret = cache[k][curr][state];
	if(ret!=0) return ret;

	for(int i=0; i<2; i++)
	{
		int next = curr + d[i];
		if(next<0 || next>=MAX) continue;

		int nextVal = Answer(k-1, next, (state | (1<<next)))%INF;
		if(nextVal != -1) 
			ret = (ret + nextVal)%INF;
	}

	return ret%INF;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin>>n;

	if(n<10) ans=0;
	else
	{
		for(int i=1; i<MAX; i++)
			ans = (ans + Answer(n-1, i, ((1<<MAX)|(1<<i)) ) %INF) %INF;
	}

	cout<<ans<<'\n';

	return 0;
}
