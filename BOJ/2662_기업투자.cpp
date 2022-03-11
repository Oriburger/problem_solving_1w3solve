#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <utility>
using namespace std;

int n, m, cache[21][301];
int arr[21][301], path[21][301];
vector<int> ans;

int GetAnswer(int idx, int money)
{
	int& ret = cache[idx][money];
	if(ret != -1) return ret; //DP
	if(money == 0 || idx == m) return ret = 0; //기저사례
	
	ret = GetAnswer(idx+1, money); //idx 기업에 투자하지 않을 경우
	for(int next = money; next >= 1; next--) //idx 기업에 money~1 투자하는 경우
	{
		int tmp = GetAnswer(idx+1, money-next)+arr[idx][next];
		if(tmp <= ret) continue; //찾은것 보다 현재 결과가 더 작다면 continue
		ret = max(ret, tmp); //ret 갱신
		path[idx][money]=next;  //GetAnswer(idx, money)가 최댓값을 반환하는 선택지
	}                           //(next만큼 투자해야 최댓값 반환)
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>m;
	
	memset(cache, -1, sizeof(cache));
	for(int i=0; i<n; i++)
	{
		int idx; cin>>idx;
		for(int j=0; j<m; j++)
			cin>>arr[j][idx];
	}
	
	cout<<GetAnswer(0, n)<<'\n'; //최대값 출력
	
	int total = n; //GetAnswer(0, n)부터 추적
	for(int i=0; i<m; i++)
	{
		ans.push_back(path[i][total]); //정답 배열에 push
		total -= path[i][total]; //total 갱신
	}
	
	for(auto &p : ans)
		cout<<p<<' ';

	return 0;
}
