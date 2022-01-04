#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
long long min_val = INF, min_duo = INF, min_trio = INF;
long long n, dice[7], max_val, ans = 0;
const vector<vector<int> > trio = {{1,2,3}, {1,3,5}, {1,4,5}, {1,2,4}, {2,3,6}
                       , {3,5,6}, {4,5,6}, {2,4,6}}; //전개도에서 찾을 수 있는 인접한 3개의 면
const vector<vector<int> > duo = {{1,2}, {1,3}, {1,4}, {1,5}, {6,2}, {6,3}, {6,4}, {6,5}
                       , {2,4}, {4,5}, {3,5}, {2,3}}; //전개도에서 찾을 수 있는 인접한 2개의 면

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=1; i<=6; i++)
	{
		cin>>dice[i];
		min_val = min(min_val, dice[i]); //주사위에서 숫자가 가장 작은 면
		max_val = max(max_val, dice[i]); //주사위에서 숫자가 가장 큰 면
		ans += dice[i]; //미리 모든 면의 합을 더함 (n==1 일 경우를 대비)
	}

        //인접한 2개의 면으로 만들 수 있는 합들 중에서 가장 작은 값
	for(auto &t : duo) min_duo = min(min_duo, dice[t[0]] + dice[t[1]]);
        //인접한 3개의 면으로 만들 수 있는 합들 중에서 가장 작은 값
	for(auto &t : trio)	min_trio = min(min_trio, dice[t[0]] + dice[t[1]] + dice[t[2]]);

	if(n==1) ans -= max_val; //n==1일 경우, 합에서 가장 큰 수만 빼면 정답
	else //n>=2일 경우
	{
		ans = pow(n-2, 2) * 5 * min_val; //1개의 면이 노출된 부분
		ans += (n-2) * 4 * min_val; //1개의 면이 노출된 부분 (바닥면)
		ans += 4 * min_trio; //3개의 면이 노출된 부분
		ans += 4 * (n-2) * min_duo + (n-1) * 4 * min_duo; //2개의 면이 노출된 부분(모서리)
	}

	cout<<ans<<'\n';

	return 0;
}
