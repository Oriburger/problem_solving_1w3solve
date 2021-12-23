/*
<참고>
- 댕어렵네
- https://blog.karatos.in/a?ID=01400-f022d8f9-2e4b-4fa6-aac1-c03a8c933452
- https://codingdog.tistory.com/entry/%EB%B0%B1%EC%A4%80-balanced-cow-subsets-%EB%B0%98%EC%9C%BC%EB%A1%9C-%EC%9E%98-%EC%AA%BC%EA%B0%9C-%EB%B4%85%EC%8B%9C%EB%8B%A4
*/
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

const int maxn = 20;
const int maxp = 1.2e6 + 5;

int n, ans, cnt=0;
vector<int> milk;
unordered_map<int, int> m;
vector<int> v[maxp];
bool visited[maxp];

void DFS(int curr, int sum, int state, const bool flag)
{
	if(curr == (!flag ? n/2 : n))
	{
		if(sum < 0) return;
		if(!flag) //첫번째 DFS
		{	
			if(m.count(sum)==0) m[sum] = ++cnt; //sum이 map에 없다면 추가
			v[m[sum]].push_back(state); //그리고 m[sum]의 vector에 state를 추가
		}
		else //두번째 DFS
		{
			if(m.count(sum)==0) return; //sum을 찾을 수 없다면 반환
			int idx = m[sum]; //상태들의 vector에 접근하기 위해 map에 접근
			for(auto &L_state : v[idx]) visited[L_state | state] = 1; //v[idx]를 순회하며, L_state | state에 방문체크
		}
		return;
	}

	DFS(curr+1, sum, state, flag); //curr 소를 추가하지 않음
	DFS(curr+1, sum+milk[curr], state + (1<<curr), flag); // A그룹에 소를 추가
	DFS(curr+1, sum-milk[curr], state + (1<<curr), flag); // B그룹에 소를 추가
}

int main()
{
	ios::sync_with_stdio(false); //입력 최적화
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	milk = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>milk[i];

	//Meet In The Middle
	DFS(0, 0, 0, false); //왼쪽 구간의 DFS를 진행
	DFS(n/2, 0, 0, true); //오른쪽 구간의 DFS도 진행

	for(int i=1; i<maxp; i++)
		ans += (int)visited[i];
	
	cout<<ans<<'\n';

	return 0;
}
