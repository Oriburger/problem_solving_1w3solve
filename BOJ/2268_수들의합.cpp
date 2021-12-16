#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct SegTree
{
	//배열의 길이
	int n;
	//각 구간의 합
	vector<long long> rangeSum;
	SegTree(const vector<long long>& arr)
	{
		n = arr.size();
		rangeSum.resize(n*4);
		init(arr, 0, n-1, 1);
	}

	//node 노드가 arr[left, right] 배열을 표현할때
	//node를 루트로 하는 서브트리를 초기화하고, 이 구간의 합을 반환
	long long init(const vector<long long>& arr, int left, int right, int node)
	{
		if(left==right)
			return rangeSum[node] = arr[left];
		int mid = (left + right) / 2;
		long long leftSum = init(arr, left, mid, node*2);
		long long rightSum = init(arr, mid+1, right, node*2+1);
		return rangeSum[node]=leftSum + rightSum;
	}

	//node가 표현하는 범위 arr[nodeLeft ... nodeRight]가 주어질 때
	// 이 범위와 arr[left, right]의 교집합의 합을 구한다. 
	long long query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		//두 구간이 겹치지 않으면, 아주 큰 값을 반환한다 : 무시됨
		if(right < nodeLeft || left > nodeRight) return 0;
		//node가 표현하는 범위가 arr[left, right]에 완전히 포함되는 경우
		if(left <= nodeLeft && nodeRight <= right) return rangeSum[node];
		
		//양쪽 구간을 나눠서 푼 뒤, 결과를 합친다. 
		int mid = (nodeLeft + nodeRight) / 2;
		return query(left, right, node*2, nodeLeft, mid)
				+ query(left, right, node*2+1, mid+1, nodeRight);
	}

	//query()를 외부에서 호출하기 위한 인터페이스
	long long query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	//arr[idx]=newVal로 바뀌었을 때, node를 루트로 하는
	//구간 트리를 갱신하고 노드가 표현하는 구간의 합을 반환한다.
	long long update(int idx, long long newVal, int node, int nodeLeft, int nodeRight)
	{
		//index가 노드가 표현하는 구간과 상관없는 경우에는 무시
		if(idx<nodeLeft || idx>nodeRight) return rangeSum[node];
		//트리의 리프까지 내려온경우
		if(nodeLeft == nodeRight) return rangeSum[node] = newVal;
		
		int mid = (nodeLeft + nodeRight) / 2;
		return rangeSum[node] =
			update(idx, newVal, node*2, nodeLeft, mid)
			+ update(idx, newVal, node*2+1, mid+1, nodeRight);
	}

	//update()를 외부에서 호출하기 위한 인터페이스
	long long update(int idx, long long newVal)
	{
		return update(idx, newVal, 1, 0, n-1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long n, m;
	vector<long long> arr;

	cin>>n>>m;
	
	arr.resize(n, 0);

	SegTree tree(arr);
	long long a, b, c;
	for(long long i=0; i<m; i++)
	{
		cin>>a>>b>>c;

		if(a==1) tree.update(b-1, c);
		else if(a==0)
		{
			if(b>c) swap(b, c);
			cout<<tree.query(b-1, c-1)<<'\n';
		}
	}

	return 0;
}
