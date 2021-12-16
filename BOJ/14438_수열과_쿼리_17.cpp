#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

typedef long long ll;

struct SegTree
{
	int n;
	vector<ll> rangeAns;
	SegTree(const vector<ll>& arr)
	{
		n = arr.size();
		rangeAns.resize(n*4);
		init(arr, 0, n-1, 1);
	}

	ll init(const vector<ll>& arr, int left, int right, int node)
	{
		if(left==right)
			return rangeAns[node] = arr[left];

		int mid = (left + right) / 2;

		ll leftVal = init(arr, left, mid, node*2);
		ll rightVal = init(arr, mid+1, right, node*2+1);

		return rangeAns[node] = min(leftVal, rightVal);
	}

	ll query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return INT_MAX;
		if(left <= nodeLeft && nodeRight <= right)
			return rangeAns[node];
	
		int mid = (nodeLeft + nodeRight) / 2;

		ll leftVal = query(left, right, node*2, nodeLeft, mid);
		ll rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		return min(leftVal, rightVal);
	}

	ll query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	ll update(int idx, int newVal, int node, int nodeLeft, int nodeRight)
	{
		if(idx < nodeLeft || idx > nodeRight) return rangeAns[node];
		if(nodeLeft == nodeRight) return rangeAns[node] = newVal;

		int mid = (nodeLeft + nodeRight) / 2;
		return rangeAns[node] = min(update(idx, newVal, node*2, nodeLeft, mid)
								, update(idx, newVal, node*2+1, mid+1, nodeRight));
	}

	ll update(int idx, ll newVal)
	{
		return update(idx, newVal, 1, 0, n-1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin>>n;
	vector<ll> arr; 
	
	arr.resize(n+1, 0);
	for(int i=1; i<=n; i++) cin>>arr[i];
	SegTree tree(arr);

	cin>>m;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;

		if(a==1) tree.update(b, c);
		else if(a==2) cout<<tree.query(b, c)<<'\n';
	}

	return 0;
}
