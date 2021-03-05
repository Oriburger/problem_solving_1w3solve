#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 100000;

struct SegTree
{
	vector<int> rangeAns, lazy;
	vector<bool> isplant;
	SegTree()
	{
		lazy.resize(MAX*4);
		rangeAns.resize(MAX*4);
		isplant.resize(MAX*4);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeAns[node];

		int mid = (nodeLeft + nodeRight) / 2;
		
		return query(left, right, node*2, nodeLeft, mid)
				+ query(left, right, node*2+1, mid+1, nodeRight);
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, MAX-1);
	}

	int update_range(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return rangeAns[node];
		if(left <= nodeLeft && nodeRight <= right)
		{
			//rangeAns[node]
			if(nodeLeft != nodeRight)
			{
				
			}
		}
		return 0;
	}

	int update_range(int left, int right)
	{
		return update_range(left, right, 1, 0, MAX-1);
	}

	void propagate(int node, int nodeLeft, int nodeRight)
	{
		
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	SegTree tree;

	cin>>n;

	for(int i=0; i<n; i++)
	{
		int l, r;
		cin>>l>>r;
		
		tree.update_range(l, r-1);
	}

	return 0;
}
