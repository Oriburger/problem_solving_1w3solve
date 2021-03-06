#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct SegTree
{
	int n;
	vector<int> rangeAns;

	SegTree(const vector<int>& arr)
	{
		n = arr.size();
		rangeAns.resize(n*4);
		init(arr, 0, n-1, 1);
	}

	int init(const vector<int>& arr, int left, int right, int node)
	{
		if(left == right) return rangeAns[node] = arr[left];

		int mid = (left + right) / 2;
		
		return rangeAns[node] = max(init(arr, left, mid, node*2)
								, init(arr, mid+1, right, node*2+1));
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeAns[node];

		int mid = (nodeLeft + nodeRight) / 2;

		return max(query(left, right, node*2, nodeLeft, mid)
				, query(left, right, node*2+1, mid+1, nodeRight));
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	vector<int> arr;

	cin>>n>>m;

	arr = vector<int>(n, 0);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	SegTree tree(arr);

	for(int i=m-1; i<=n-m; i++)
		cout<<tree.query(i-(m-1), i+(m-1), 1, 0, n-1)<<' ';

	return 0;
}
