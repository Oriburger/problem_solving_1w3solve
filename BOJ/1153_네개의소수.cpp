#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 1000001;

int n;
bool flag = false;
vector<int> prime, ans;
vector<bool> isPrime(MAX, true);

void GetAnswer(int idx, int curr, int toPick)
{
	if(flag) return;
	if(curr == 0)
	{
		if(toPick) return;
		flag = true;
		return;
	}
	
	for(int i=idx; i>=0; i--)
	{
		if(curr - prime[i] < 0) continue;
		
		ans.push_back(prime[i]);
		GetAnswer(idx-1, curr-prime[i], toPick-1);
		if(flag) return;
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 
	
	cin>>n;
	
	isPrime[0] = isPrime[1] = false;
	for(int i=2; i<=n; i++)
		for(int j=2; i*j<=n; j++)
			isPrime[i*j]=false;
	
	for(int i=2; i<=n; i++)
		if(isPrime[i]) prime.push_back(i);

	GetAnswer(prime.size()-1, n	, 4);
	
	if(ans.size()<4)
	{
		cout<<-1<<'\n';
		return 0;
	}
	
	for(int i=3; i>=0; i--)
		cout<<ans[i]<<' ';
	cout<<'\n';
	
	return 0;
}
