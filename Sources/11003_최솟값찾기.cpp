#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;

int n, l;
priority_queue<P, vector<P>, greater<P> > pq; 
vector<int> ans;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>l;
	for(int i=0; i<n; i++)
	{
		int tmp; cin>>tmp;
		pq.push({tmp, i});

		while(1)
		{
			P curr = pq.top();
			if(curr.second < i-l+1) pq.pop();
			else ans.push_back(curr.first);
		}
	}
	for(const auto k : ans)
		cout<<k<<' ';

	return 0;
}
