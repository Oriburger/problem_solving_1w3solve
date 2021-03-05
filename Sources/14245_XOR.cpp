#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct SegTree
{
	int n;
	vector<int> rangeAns, lazy;
	SegTree(const vector<int>& arr)
	{
		n = arr.size();
		lazy.resize(n*4, 0);
		rangeAns.resize(n*4, 0);
		init(arr, 0, n-1, 1);
	}

	int init(const vector<int>& arr, int left, int right, int node)
	{
		if(left == right) return rangeAns[node] = arr[left];

		int mid = (left + right) / 2;

		return rangeAns[node] = init(arr, left, mid, node*2)
								^ init(arr, mid+1, right, node*2+1);
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		propagate(node, nodeLeft, nodeRight);

		if(right < nodeLeft || left > nodeRight) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeAns[node];

		int mid = (nodeLeft + nodeRight) / 2;
		
		return query(left, right, node*2, nodeLeft, mid)
				^ query(left, right, node*2+1, mid+1, nodeRight);
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	int update_range(int left, int right, int newVal, int node, int nodeLeft, int nodeRight)
	{
		propagate(node, nodeLeft, nodeRight);

		if(right < nodeLeft || left > nodeRight) return rangeAns[node];
		if(left <= nodeLeft && nodeRight <= right)
		{
			rangeAns[node] ^= newVal* ((nodeRight - nodeLeft + 1)%2);
			if(nodeLeft != nodeRight)
			{
				lazy[node*2] ^= newVal;
				lazy[node*2+1] ^= newVal;
			}
			return rangeAns[node];
		}
		int mid = (nodeLeft + nodeRight) / 2;

		return rangeAns[node] = (update_range(left, right, newVal, node*2, nodeLeft, mid)
							^ update_range(left, right, newVal, node*2+1, mid+1, nodeRight));
	}

	int update_range(int left, int right, int newVal)
	{
		return update_range(left, right, newVal, 1, 0, n-1);
	}

	void propagate(int node, int nodeLeft, int nodeRight)
	{
		if(!lazy[node]) return;

		rangeAns[node] ^= lazy[node] * ((nodeRight - nodeLeft + 1)%2);
		
		if(nodeLeft != nodeRight)
		{
			lazy[node*2] ^= lazy[node];
			lazy[node*2+1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	vector<int> arr;

	cin>>n;
	arr.resize(n+1);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	SegTree tree(arr);
	
	cin>>m;
	for(int i=0; i<m; i++)
	{	
		int a, b, c, d;
		cin>>a>>b;

		if(a==1)
		{
			cin>>c>>d;
			tree.update_range(b, c, d);
		}
		else
			cout<<tree.query(b, b)<<'\n';
	}

	return 0;
}
