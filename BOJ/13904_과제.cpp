#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, fin, ans;
priority_queue<int> task[1001];

bool comp(const P& p, const P& q)
{
	if(p.first == q.first) return p.second < q.second;
	return p.first > q.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
		
	cin>>n;
	
	for(int i=0; i<n; i++)
	{
		int d, w;
		cin>>d>>w;
		fin = max(d, fin);
		task[d].push(w);
	}
	
	for(int d=fin; d>0; d--)
	{
		int tmp = 0, idx = -1;
		for(int k=d; k<=fin; k++)
		{
			if(task[k].empty()) continue;
			if(tmp <= task[k].top())
			{
				tmp = task[k].top();
				idx = k;
			}
		}
		if(idx == -1) continue;
		task[idx].pop();
		ans += tmp;
	}

	cout<<ans<<'\n';
	
	return 0;
}
