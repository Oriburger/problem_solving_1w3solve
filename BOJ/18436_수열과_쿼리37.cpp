#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

struct SegTree
{
	int n;
	vector<P> rangeAns;
	SegTree(const vector<int>& arr)
	{
		n = arr.size();
		rangeAns.resize(n*4);
		init(arr, 0, n-1, 1);
	}

	P init(const vector<int>& arr, int left, int right, int node)
	{
		if(left == right) return rangeAns[node] = {arr[left]%2, !(arr[left]%2)};

		int mid = (left + right)/2;
		P leftVal = init(arr, left, mid, node*2);
		P rightVal = init(arr, mid+1, right, node*2+1);

		return rangeAns[node] = {leftVal.first + rightVal.first
								, leftVal.second + rightVal.second};
	}

	P query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || nodeRight < left) return {0, 0};
		if(left <= nodeLeft && nodeRight <= right) return rangeAns[node];

		int mid = (nodeLeft + nodeRight) / 2;
		P leftVal = query(left, right, node*2, nodeLeft, mid);
		P rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		return {leftVal.first + rightVal.first
				, leftVal.second + rightVal.second};
	}

	P query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	P update(int idx, int newVal, int node, int nodeLeft, int nodeRight)
	{
		if(idx < nodeLeft || nodeRight < idx) return rangeAns[node];
		if(nodeLeft == nodeRight) return rangeAns[node] = {newVal%2, !(newVal%2)};

		int mid = (nodeLeft + nodeRight) / 2;
		P leftVal = update(idx, newVal, node*2, nodeLeft, mid);
		P rightVal = update(idx, newVal, node*2+1, mid+1, nodeRight);

		return rangeAns[node] = {leftVal.first + rightVal.first
								, leftVal.second + rightVal.second};	
	}

	P update(int idx, int newVal)
	{
		return update(idx, newVal, 1, 0, n-1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m;
	vector<int> arr;

	cin>>n;
	arr = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	SegTree tree(arr);

	cin>>m;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;
		
		if(a==1) tree.update(b-1, c);
		else if(a==2) cout<<tree.query(b-1, c-1).second<<'\n';
		else if(a==3) cout<<tree.query(b-1, c-1).first<<'\n';
	}

	return 0;
}
