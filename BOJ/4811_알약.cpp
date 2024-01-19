#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int n;
ll cache[31][61]; //DP[W][H] = 큰 알약 W개와 작은 알약 H개를 먹을 수 있는 경우의 수
//2*w + h = 2n

ll getAnswer(int w, int h)
{
	ll& ret = cache[w][h];
	if(ret != 0) return ret; 
	if(w == 0) return ret = 1;
	
	if(w > 0) ret = getAnswer(w-1, h+1);	
	if(h > 0) ret += getAnswer(w, h-1);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	while(1)
	{
		cin>>n; 
		if(n==0) break;
		
		cout<<getAnswer(n, 0)<<'\n';
	}
	
	return 0;
}
