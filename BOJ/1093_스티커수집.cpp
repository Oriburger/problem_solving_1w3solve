#include <bits/stdc++.h>
using namespace std;
#define FRONT 0
#define BACK 1

const int INF = INT_MAX;
int n, k, tmp, sum, ans;
vector<int> cost, value;
map<int, int> m[2];

void DFS(int curr, const bool isBack, int cost_sum, int value_sum) 
{
	if(curr == (!isBack ? n/2 : n)) //끝에 도달했다면
	{
		if(m[isBack].count(value_sum)==0) m[isBack][value_sum] = cost_sum; 
		else m[isBack][value_sum] = min(m[isBack][value_sum], cost_sum); //value_sum의 최소를 구함
		return;
	}
	DFS(curr+1, isBack, cost_sum, value_sum);
	DFS(curr+1, isBack, cost_sum + cost[curr], value_sum + value[curr]);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	value = cost = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>cost[i];
	for(int i=0; i<n; i++)
		cin>>value[i];

	cin>>k>>tmp;
	
	while(tmp--)
	{
		int id;	cin>>id;
		sum += cost[id]; //기존에 보유한 스티커들 다 판매
	}
	
	DFS(0, false, 0, 0); //왼쪽
	DFS(n/2, true, 0, 0); //오른쪽

	tmp = INF;
	auto q = m[BACK].end(); //오른쪽 배열은 뒤에서부터 스타트
	int r_min = (--q)->second; //오른쪽 구간의 최소 cost, 가장 뒤에 있는 원소의 cost로 초기화

	for(auto &p : m[FRONT]) //왼쪽 배열을 앞에서부터 순회
		while(p.first + q->first >= k) //p.value + q.value가 k이상이면 반복
		{
			tmp = min(tmp, p.second + r_min); //정답 갱신
			if(q == m[BACK].begin()) break; //q가 맨 앞에 왔다면 break
			else if(p.first + (--q)->first < k){ q++; break; } 
     		        //q를 하나 앞으로 땡겨서 합이 k보다 작으면 q를 다시 증가시키고 break;
			else r_min = min(r_min, q->second); //오른쪽 구간의 최소 cost를 갱신
		}
	if(tmp == INF) ans = -1; //정답을 찾지 못함.
	else ans = max(tmp - sum, 0); //sum : 첨에 갖고 있던 스티커들을 팔아서 번 돈
                          	      //tmp - sum이 0보다 작으면 돈이 필요없음
                              	      // ㄴ> 기존의 돈으로 해결이 가능하다는 의미

	cout<<ans<<'\n';

	return 0;
}
