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
	if(flag) return;  //정답을 찾았으면 반환
	if(curr == 0)
	{
		if(toPick) return;
		flag = true; //정답을 찾음
		return; 
	}
	
	for(int i=idx; i>=0; i--) //되도록 큰 수 부터 뺀다.
	{
		if(curr - prime[i] < 0) continue; //음수가 되면 continue
		
		ans.push_back(prime[i]);
		GetAnswer(idx-1, curr-prime[i], toPick-1);
		if(flag) return; //정답을 찾았으면 반환
		ans.pop_back(); //backtrack!
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL); 
	
	cin>>n;
	
	isPrime[0] = isPrime[1] = false; //에라토스테네스의 체
	for(int i=2; i<=n; i++)
		for(int j=2; i*j<=n; j++)
			isPrime[i*j]=false;
	
	for(int i=2; i<=n; i++) //소수들을 따로 집합으로 빼줌
		if(isPrime[i]) prime.push_back(i);

	GetAnswer(prime.size()-1, n	, 4); //큰 수부터 빼면서 탐색을 진행
	
	if(ans.size()<4) //정답을 찾지 못했다면?
	{
		cout<<-1<<'\n'; //-1 출력
		return 0; 
	}
	
	for(int i=3; i>=0; i--) //정답 출력
		cout<<ans[i]<<' ';
	cout<<'\n';
	
	return 0;
}
