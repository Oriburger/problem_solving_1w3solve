#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;
typedef vector<P>::iterator viter;

struct Comp
{
	bool operator()(P& a, P& b)
	{
		if(a.first != b.first) return a.first > b.first;
		return a.second < b.second;	
	}
};


int n, k;
long long ans=0;
vector<int> c;
priority_queue<P, vector<P>, Comp> pq;
priority_queue<int, vector<int>> tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n>>k;

	for(int i=0; i<n; i++)
	{
		int m, v;
		cin>>m>>v;
		pq.push({m, v});
	}
	
	c = vector<int>(k, 0);
	for(int i=0; i<k; i++)
		cin>>c[i];
	
	sort(c.begin(), c.end());
	for(auto &curr : c)
	{
		while(1)
		{
			if(pq.top().first > curr || pq.empty()) break;

			tmp.push(pq.top().second);
			pq.pop();
		}

		if(!tmp.empty())
		{
			ans += tmp.top();
			tmp.pop();
		}
	}

	cout<<ans<<'\n';

	return 0;
}
