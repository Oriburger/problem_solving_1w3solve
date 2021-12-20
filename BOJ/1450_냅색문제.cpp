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
	if(curr == (!isBack ? n/2 : n))
	{
		if(m[isBack].count(value_sum)==0) m[isBack][value_sum] = cost_sum;
		else m[isBack][value_sum] = min(m[isBack][value_sum], cost_sum);
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
		sum += cost[id];
	}
	
	DFS(0, false, 0, 0);
	DFS(n/2, true, 0, 0);

	tmp = INF;
	auto q = m[BACK].end();
	int r_min = (--q)->second;
	for(auto &p : m[FRONT])
	{
		while(p.first + q->first >= k)
		{
			tmp = min(tmp, p.second + r_min);
			if(q == m[BACK].begin()) break;
			else if(p.first + (--q)->first < k){ q++; break; }
			else r_min = min(r_min, q->second);
		}
	}
	if(tmp == INF) ans = -1;
	else ans = max(tmp - sum, 0);

	cout<<ans<<'\n';

	return 0;
}

//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, c, ans;
vector<ll> arr, front, back;


void DFS(int curr, const int end, int sum)
{
	if(sum > c) return; //양수만 주어지기 때문에 c를 초과하면 답에 포함되지 않음
	if(curr == end) //끝에 도달했다면, sum을 각 배열에 넣어줌
	{
		if(end == n/2) front.push_back(sum);
		else back.push_back(sum);
		return;
	}

	DFS(curr+1, end, sum);
	DFS(curr+1, end, sum + arr[curr]);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>c;
	
	arr = vector<ll>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	DFS(0, n/2, 0); //왼쪽 부분
	DFS(n/2, n, 0); //오른쪽 부분

	sort(back.begin(), back.end()); //뒤의 부분을 정렬

	for(auto &p : front) //front를 순회하며 c-p를 넘지않는 멤버의 개수를 더해준다.
		ans += upper_bound(back.begin(), back.end(), c-p) - back.begin();

	cout<<ans<<'\n';

	return 0;
}
