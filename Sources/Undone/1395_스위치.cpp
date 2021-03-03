#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct SegTree
{
	int n;
	vector<int> rangeAns;
	vector<bool> lazy;
	SegTree(int k)
	{
		n = k;
		rangeAns.resize(n*4);
		lazy.resize(n*4, false);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		propagate(node, nodeLeft, nodeRight);
		
		if(right < nodeLeft || nodeRight < left) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeAns[node];

		int mid = (nodeLeft + nodeRight) / 2;
		int leftVal = query(left, right, node*2, nodeLeft, mid);
		int rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		return leftVal + rightVal;
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	int update_range(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		propagate(node, nodeLeft, nodeRight);

		if(right < nodeLeft || nodeRight < left) return rangeAns[node];

		if(left <= nodeLeft && nodeRight <= right)
		{
			rangeAns[node] = (nodeRight - nodeLeft + 1) - rangeAns[node];
			if(nodeLeft != nodeRight)
			{
				lazy[node*2] += newVal;
				lazy[node*2+1] += newVal;
			}
			return rangeAns[node];
		}

		int mid = (nodeLeft + nodeRight) / 2;

		return rangeAns[node] = update_range(left, right, node*2, nodeLeft, mid)
								+ update_range(left, right, node*2+1, mid+1, nodeRight);
	}

	int update_range(int left, int right)
	{
		return update_range(left, right, 1, 0, n-1);
	}

	void propagate(int node, int nodeLeft, int nodeRight)
	{
		if(!lazy[node]) return;

		rangeAns[node] += (nodeRight - nodeLeft + 1) * lazy[node];

		if(nodeLeft != nodeRight)
		{
			lazy[node*2] += lazy[node];
			lazy[node*2+1] += lazy[node];
		}
		lazy[node] = 0;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m;

	cin>>n>>m;	
	SegTree tree(n); 

	for(int i=0; i<m; i++)
	{
		int a, b, c;

		cin>>a>>b>>c;

		if(a==0) tree.update_range(b-1, c-1);
		else cout<<tree.query(b-1, b-1)<<'\n';
	}

	return 0;
}
