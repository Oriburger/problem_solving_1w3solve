#include <iostream>
#include <vector>
#include <climits>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, int> P;

bool CompPair(const P& p1, const P& p2)
{
	if(p1 < p2) return true;
	else if(p1 > p2) return false;
	return p1.second < p2.second;
}

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
		//리프 노드까지 내려왔다면,
		if(left == right) return rangeAns[node] = {arr[left], left};

		int mid = (left + right) / 2;
		P leftVal = init(arr, left, mid, node*2); //왼쪽 자식의 idx는 node * 2
		P rightVal = init(arr, mid+1, right, node*2+1); //오른쪽 자식은 node * 2 + 1

		if(CompPair(leftVal, rightVal)) return rangeAns[node] = leftVal;
		return rangeAns[node] = rightVal;
	}

	P query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		//[left, right]가 노드의 범위를 벗어난다면 (노드와 겹치지 않는다면)
		if(right < nodeLeft || left > nodeRight) return {INT_MAX, INT_MAX};
		//[left, right]가 노드와 완전히 겹친다면
		if(left <= nodeLeft && nodeRight <= right) return rangeAns[node];

		//분할정복
		int mid = (nodeLeft + nodeRight) / 2;
		P leftVal = query(left, right, node*2, nodeLeft, mid);
		P rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		if(CompPair(leftVal, rightVal)) return leftVal;
		return rightVal;
	}

	ll query(int left, int right)
	{
		return query(left, right, 1, 0, n-1).second;
	}

	//arr[idx] = newVal
	//node를 루트로 하는 구간 트리를 갱신, 노드가 표현하는 구간해를 반환
	P update(int idx, ll newVal, int node, int nodeLeft, int nodeRight)
	{
		//idx와 노드 표현 구간과 겹치지 않는다면, 
		if(idx < nodeLeft || idx > nodeRight) return rangeAns[node];
		//트리의 리프까지 도달한 경우 갱신
		if(nodeLeft == nodeRight) return rangeAns[node] = {newVal, rangeAns[node].second};

		int mid = (nodeLeft + nodeRight) / 2;
		P leftVal = update(idx, newVal, node*2, nodeLeft, mid);
		P rightVal = update(idx, newVal, node*2+1, mid+1, nodeRight);

		if(CompPair(leftVal, rightVal)) return rangeAns[node] = leftVal;
		return rangeAns[node] = rightVal;
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

	int n, m;
	vector<ll> arr;

	cin>>n;
	arr = vector<ll>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];

	SegTree tree(arr);

	cin>>m;
	for(int i=0; i<m; i++)
	{
		int a, b, c;
		cin>>a>>b>>c;

		if(a==1) tree.update(b-1, c);
		else cout<<tree.query(b-1, c-1)+1<<'\n';
	}

	return 0;
}
