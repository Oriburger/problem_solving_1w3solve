#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX;
long long min_val=INF, min_duo=INF, min_trio=INF;
long long n, dice[7], max_val, ans = 0;
const vector<vector<int> > trio = {{1,2,3}, {1,3,5}, {1,4,5}, {1,2,4}
								 , {2,3,6}, {3,5,6}, {4,5,6}, {2,4,6}};
const vector<vector<int> > duo = {{1,2}, {1,3}, {1,4}, {1,5}, {6,2}, {6,3}
								 ,{6,4}, {6,5}, {2,4}, {4,5}, {3,5}, {2,3}};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;
	for(int i=1; i<=6; i++)
	{
		cin>>dice[i];
		min_val = min(min_val, dice[i]);
		max_val = max(max_val, dice[i]);
		ans += dice[i];
	}

	for(auto &t : duo) min_duo = min(min_duo, dice[t[0]] + dice[t[1]]);
	for(auto &t : trio)	min_trio = min(min_trio, dice[t[0]] + dice[t[1]] + dice[t[2]]);

	if(n==1) ans -= max_val;
	else
	{
		ans = pow(n-2, 2) * 5 * min_val;
		ans += 4 * min_trio;
		ans += (n-2) * 4 * min_val;
		ans += 4 * (n-2) * min_duo + (n-1) * 4 * min_duo;
	}

	cout<<ans<<'\n';

	return 0;
}
