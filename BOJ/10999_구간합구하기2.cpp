#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

typedef long long ll;

struct SegTree
{
	int n;
	vector<ll> rangeAns, lazy;
	SegTree(const vector<ll>& arr)
	{
		n = arr.size();
		rangeAns.resize(n*4);
		lazy.resize(n*4);
		init(arr, 0, n-1, 1);
	}

	ll init(const vector<ll>& arr, int left, int right, int node)
	{
		if(left==right)
			return rangeAns[node] = arr[left];

		int mid = (left + right) / 2;
		ll leftVal = init(arr, left, mid, node*2);
		ll rightVal = init(arr, mid+1, right, node*2+1);

		return rangeAns[node] = leftVal + rightVal;
	}

	ll query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		propagate(node, nodeLeft, nodeRight);

		if(right < nodeLeft || left > nodeRight) return 0;
		if(left <= nodeLeft && nodeRight <= right)
			return rangeAns[node];
	
		int mid = (nodeLeft + nodeRight) / 2;
		ll leftVal = query(left, right, node*2, nodeLeft, mid);
		ll rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		return leftVal + rightVal;
	}

	ll query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	ll update_range(int left, int right, ll newVal, int node, int nodeLeft, int nodeRight)
	{
		propagate(node, nodeLeft, nodeRight);

		if(right < nodeLeft || nodeRight < left) return rangeAns[node];

		if(left <= nodeLeft && nodeRight <= right)
		{
			rangeAns[node] += newVal * (nodeRight - nodeLeft + 1);
			if(nodeLeft != nodeRight)
			{
				lazy[node*2] += newVal;
				lazy[node*2+1] += newVal;
			}
			return rangeAns[node];
		}

		int mid = (nodeLeft + nodeRight) / 2;

		return rangeAns[node] = update_range(left, right, newVal, node*2, nodeLeft, mid)
							+ update_range(left, right, newVal, node*2+1, mid+1, nodeRight);
	}

	ll update_range(int left, int right, ll newVal)
	{
		return update_range(left, right, newVal, 1, 0, n-1);
	}

	void propagate(int node, int nodeLeft, int nodeRight)
	{
		if(lazy[node]==0) return;

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

	int n, m, k;
	vector<ll> arr; 
	
	cin>>n>>m>>k;

	arr.resize(n, 0);
	for(int i=0; i<n; i++) cin>>arr[i];
	SegTree tree(arr);

	for(int i=0; i<m+k; i++)
	{
		int a, b, c, d;
		cin>>a>>b>>c;

		if(a==1)
		{
			cin>>d;
			tree.update_range(b-1, c-1, d);
		}
		else
		{
			cout<<tree.query(b-1, c-1)<<'\n';
		}
	}

	return 0;
}
