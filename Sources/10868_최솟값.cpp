#include <iostream>
#include <vector>
using namespace std;

const int INF = 2100000000;

struct SegTree
{
	int n;
	vector<int> rangeMin;

	SegTree(const vector<int>& arr)
	{
		n = arr.size();
		rangeMin.resize(n*4);
		Init(arr, 0, n-1, 1);
	}

	int Init(const vector<int>& arr, int left, int right, int node)
	{
		if(left == right) 
			return rangeMin[node] = arr[left];

		int mid = (left + right)/2;
		int leftMin = Init(arr, left, mid, node*2);
		int rightMin = Init(arr, mid+1, right, node*2+1);
		
		return rangeMin[node] = min(leftMin, rightMin);
	}

	int Query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return INF;
		if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];

		int mid = (nodeLeft + nodeRight)/2;
		return min(Query(left, right, node*2, nodeLeft, mid)
					, Query(left, right, node*2+1, mid+1, nodeRight));
	}

	int Query(int left, int right)
	{
		return Query(left, right, 1, 0, n-1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	vector<int> arr;

	cin>>n>>m;
	
	arr.resize(n);
	for(int i=0; i<n; i++) 
		cin>>arr[i];

	SegTree st(arr);
	
	for(int i=0; i<m; i++)
	{
		int a, b;
		cin>>a>>b;
		cout<<st.Query(a-1, b-1)<<'\n';
	}

	return 0;
}
