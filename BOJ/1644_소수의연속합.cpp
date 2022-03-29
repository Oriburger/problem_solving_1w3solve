#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, sum, ans;
const int MAX = 4000000;
vector<bool> isPrime(MAX+1, true);
queue<int> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	isPrime[1]=false;
	for(int i=2; i<=n; i++)
		for(int j=2; i*j<=n; j++)
			isPrime[i*j]=false;		
	
	for(int i=2; i<=n; i++)
	{
		if(!isPrime[i]) continue;
		bool flag = false;
		
		q.push(i);
		sum += i;
		
		while(sum > n)
		{
			sum -= q.front();
			q.pop();
		}
		if(sum == n) ans++;
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
