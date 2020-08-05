#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int INF = 2100000000;
typedef pair<int, int> P;

struct SegTree
{
	int n; //배열의 길이
	vector<P> rangeAns; //구간의 {높이 최소값, 넓이 최대값} 저장

	SegTree(const vector<int>& arr)
	{
		n = arr.size();
		//이진트리 표현 위해 사이즈는 넉넉히 x4
		rangeAns.resize(n*4); 
		Init(arr, 0, n-1, 1);
	}

	P Init(const vector<int>& arr, int left, int right, int node)
	{
		if(left == right)
			return rangeAns[node] = {arr[left], arr[left]};

		int mid = (left + right)/2;
		//좌측, 우측의 최댓값을 구한다.
		P leftAns = Init(arr, left, mid, node*2);
		leftAns.second = max(leftAns.second, (mid-left+1)*leftAns.first);
		P rightAns = Init(arr, mid+1, right, node*2+1);
		rightAns.second = max(rightAns.second, (right-(mid+1)+1)*rightAns.first);

		cout<<left+1<<","<<right+1<<")"<<max(leftAns.second, rightAns.second)<<'\n';

		return rangeAns[node] = {min(leftAns.first, rightAns.first)
								, max(leftAns.second, rightAns.second)};
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	{
		int n; cin>>n;
		
		if(n==0) break;

		vector<int> arr(n);
		for(int i=0; i<n; i++)
			cin>>arr[i];
		
		SegTree st(arr);

		cout<<st.rangeAns[1].second<<'\n';
	}

	return 0;
}
