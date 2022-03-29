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
	
	isPrime[1]=false; //1은 소수가 아님
	for(int i=2; i<=n; i++) //에라토스테네스의-체
		for(int j=2; i*j<=n; j++) //i*j가 n이 될 때 까지만 반복
			isPrime[i*j]=false; 
	
	for(int i=2; i<=n; i++) //2~n 
	{
		if(!isPrime[i]) continue; //소수가 아니면 continue
	
		q.push(i); //큐에 넣음
		sum += i; //합에도 더함
		
		while(sum > n) //sum이 n보다 큰 경우
		{
			sum -= q.front(); //큐의 앞에서 꺼내서 합에서 빼줌
			q.pop(); //큐에서 꺼냄
		}
		if(sum == n) ans++; //만약 합이 n이 되는 경우를 찾았다면 정답 +1
	}
	cout<<ans<<'\n';
	
	return 0;
}
