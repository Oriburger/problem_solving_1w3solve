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
	vector<ll> sum;
	SegTree(const vector<ll>& arr)
	{
		n = arr.size();
		sum.resize(n);
		rangeAns.resize(n*4);
		init(arr, 0, n-1, 1);

		sum[0] = arr[0];
		for(int i=1; i<n; i++)
			sum[i]=sum[i-1] + arr[i];
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
		return rangeAns[node] = leftVal;
	}

	P query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return {INT_MAX, -1};
		if(left <= nodeLeft && nodeRight <= right)
			return rangeAns[node];
	
		int mid = (nodeLeft + nodeRight) / 2;

		P leftVal = query(left, right, node*2, nodeLeft, mid);
		P rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		if(leftVal.first > rightVal.first)
			return rightVal;
		return leftVal;
	}

	P query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	ll GetAnswer(int left, int right)
	{
		if(left < 0 || left > right || right >= n) return 0;

		P minVal = query(left, right);

		ll ret = (sum[right]-sum[left-1]) * minVal.first;

		if(left == right) return ret;

		ret = max(ret, GetAnswer(left, minVal.second-1));
		ret = max(ret, GetAnswer(minVal.second+1, right));

		return ret;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	vector<ll> arr; 
	
	arr.resize(n+1, 0);
	for(int i=1; i<=n; i++)
		cin>>arr[i];

	SegTree tree(arr);

	cout<<tree.GetAnswer(1, n)<<'\n';

	return 0;
}
