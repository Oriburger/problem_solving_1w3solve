#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

struct SegTree
{
	int n;
	vector<ll> rangeSum;
	SegTree(int N)
	{
		n = N;
		rangeSum.resize(n*4, 0);
	}

	ll Query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];

		int mid = (nodeLeft + nodeRight) / 2;
		return Query(left, right, node*2, nodeLeft, mid)
				+ Query(left, right, node*2+1, mid+1, nodeRight);
	}

	ll Update(int idx, ll newVal, int node, int nodeLeft, int nodeRight)
	{
		if(idx<nodeLeft || idx>nodeRight) return rangeSum[node];
		if(nodeLeft==nodeRight) return rangeSum[node]+=newVal;

		int mid = (nodeLeft + nodeRight) / 2;
		return rangeSum[node] = Update(idx, newVal, node*2, nodeLeft, mid)
								+ Update(idx, newVal, node*2+1, mid+1, nodeRight);
	}

	//============================

	ll Query(int left, int right)
	{
		return Query(left, right, 1, 0, n-1);
	}

	ll Update(int idx, ll newVal)
	{
		return Update(idx, newVal, 1, 0, n-1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, q;
	cin>>n>>q;

	SegTree st(n);
	
	for(int i=0; i<q; i++)
	{
		int a, b, c;

		cin>>a>>b>>c;

		if(a==1)
			st.Update(b-1, c);
		else if(a==2)
			cout<<st.Query(b-1, c-1)<<'\n';
	}

	return 0;
}
