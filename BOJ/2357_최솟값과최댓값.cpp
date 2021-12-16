#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

typedef pair<int, int> P;

struct SegTree
{
	//배열의 길이
	int n;
	//각 구간의 최소, 최대치
	vector<P> range;
	SegTree(const vector<int>& arr)
	{
		n = arr.size();
		range.resize(n*4);
		init(arr, 0, n-1, 1);
	}

	//node 노드가 arr[left, right] 배열을 표현할때
	//node를 루트로 하는 서브트리를 초기화하고, 이 구간의 최소, 최대치를 반환
	P init(const vector<int>& arr, int left, int right, int node)
	{
		if(left==right)
			return range[node] = {arr[left], arr[left]};
		int mid = (left + right) / 2;

		P leftVal = init(arr, left, mid, node*2);
		P rightVal = init(arr, mid+1, right, node*2+1);

		return range[node]={min(leftVal.first, rightVal.first)
							, max(leftVal.second, rightVal.second)};
	}

	//node가 표현하는 범위 arr[nodeLeft ... nodeRight]가 주어질 때
	// 이 범위와 arr[left, right]의 교집합의 최소, 최대치를 구한다. 
	P query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		//두 구간이 겹치지 않으면, 아주 큰 값을 반환한다 : 무시됨
		if(right < nodeLeft || left > nodeRight) return {INT_MAX, -1};
		//node가 표현하는 범위가 arr[left, right]에 완전히 포함되는 경우
		if(left <= nodeLeft && nodeRight <= right) return range[node];
		
		//양쪽 구간을 나눠서 푼 뒤, 결과를 합친다. 
		int mid = (nodeLeft + nodeRight) / 2;

		P leftVal = query(left, right, node*2, nodeLeft, mid);
		P rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		return {min(leftVal.first, rightVal.first), max(leftVal.second, rightVal.second)};
	}

	//query()를 외부에서 호출하기 위한 인터페이스
	P query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	//arr[idx]=newVal로 바뀌었을 때, node를 루트로 하는
	//구간 트리를 갱신하고 노드가 표현하는 구간의 최소, 최대를 반환한다.
	P update(int idx, int newVal, int node, int nodeLeft, int nodeRight)
	{
		//index가 노드가 표현하는 구간과 상관없는 경우에는 무시
		if(idx<nodeLeft || idx>nodeRight) return range[node];
		//트리의 리프까지 내려온경우
		if(nodeLeft == nodeRight) return range[node] = {newVal, newVal};
		
		int mid = (nodeLeft + nodeRight) / 2;
		
		P leftVal = update(idx, newVal, node*2, nodeLeft, mid);
		P rightVal = update(idx, newVal, node*2+1, mid+1, nodeRight);

		return range[node] = {min(leftVal.first, rightVal.first), max(leftVal.second, rightVal.second)};
	}

	//update()를 외부에서 호출하기 위한 인터페이스
	P update(int idx, int newVal)
	{
		return update(idx, newVal, 1, 0, n-1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a, b;
	vector<int> arr;

	cin>>n>>m;
	arr.resize(n);

	for(int i=0; i<n; i++)
		cin>>arr[i];

	SegTree st(arr);

	for(int i=0; i<m; i++)
	{
		cin>>a>>b;

		P curr = st.query(a-1, b-1);
		cout<<curr.first<<' '<<curr.second<<'\n';
	}

	return 0;
}
