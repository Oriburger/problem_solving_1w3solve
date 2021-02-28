#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

struct SegTree
{
	int n;
	vector<P> rangeAns;
	SegTree(const vector<ll>& arr)
	{
		n = arr.size();
		rangeAns.resize(n*4);
		init(arr, 0, n-1, 1);
	}

	P init(const vector<ll>& arr, int left, int right, int node)
	{
		if(left==right)
			return rangeAns[node] = {arr[left], left};

		int mid = (left + right) / 2;

		P leftVal = init(arr, left, mid, node*2);
		P rightVal = init(arr, mid+1, right, node*2+1);

		if(leftVal.first > rightVal.first)
			return rangeAns[node] = rightVal;
		else if(leftVal.first == rightVal.first)
		{
			if(leftVal.second > rightVal.second) 
				return rangeAns[node] = rightVal;
			return rangeAns[node] = leftVal;
		}
		return rangeAns[node] = leftVal;
	}

	P query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return {INT_MAX, INT_MAX};
		if(left <= nodeLeft && nodeRight <= right)
			return rangeAns[node];
	
		int mid = (nodeLeft + nodeRight) / 2;

		P leftVal = query(left, right, node*2, nodeLeft, mid);
		P rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		if(leftVal.first > rightVal.first) return rightVal;
		else if(leftVal.first == rightVal.first)
		{
			if(leftVal.second > rightVal.second) return rightVal;
			return leftVal;
		}
		return leftVal;
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, n-1).second+1;
	}

	P update(int idx, ll newVal, int node, int nodeLeft, int nodeRight)
	{
		if(idx < nodeLeft || idx > nodeRight) return rangeAns[node];
		if(nodeLeft == nodeRight) 
			return rangeAns[node] = {newVal, rangeAns[node].second};

		int mid = (nodeLeft + nodeRight) / 2;

		P leftVal = update(idx, newVal, node*2, nodeLeft, mid);
		P rightVal = update(idx, newVal, node*2+1, mid+1, nodeRight);

		if(leftVal.first > rightVal.first) 
			return rangeAns[node] = rightVal;
		else if(leftVal.first == rightVal.first)
		{
			if(leftVal.second > rightVal.second) 
				return rangeAns[node] = rightVal;
			return rangeAns[node] = leftVal;
		}
		return rangeAns[node] = leftVal;
	}

	P update(int idx, ll newVal)
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
	
	arr.resize(n, 0);
	for(int i=0; i<n; i++) cin>>arr[i];
	SegTree tree(arr);

	cin>>m;
	for(int i=0; i<m; i++)
	{
		int a, b;
		long long c;
		cin>>a;

		if(a==1)
		{
			cin>>b>>c;
			tree.update(b-1, c);
		}
		else if(a==2) cout<<tree.query(0, n-1)<<'\n';
	}

	return 0;
}
