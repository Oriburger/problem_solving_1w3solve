#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

struct Lunch { ull m, e; };

ull t, n, ans;
vector<Lunch> l;

bool comp(Lunch &l1, Lunch &l2)
{
	if(l1.e == l2.e) return l1.m > l2.m;
	return l1.e > l2.e; //먹는 시간이 오래 걸리는게 앞으로 오도록
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>t;

	while(t--)
	{
		cin>>n;

		ans = 0;
		l = vector<Lunch>(n);
		for(int i=0; i<n; i++)
			cin>>l[i].m;
		for(int i=0; i<n; i++)
			cin>>l[i].e;

		sort(l.begin(), l.end(), comp); //먹는 시간을 기준으로 내림차순 정렬
		
		ull tmp = 0;
		for(const auto &p : l) //l을 순회하며
		{
			tmp += p.m; //현재까지 총 데운 시간을 구함
			ans = max(ans, tmp+p.e); //먹는 시간 + 총 데운 시간 중에서 정답을 도출
		}
		cout<<ans<<'\n';
	}	

	return 0;
}
