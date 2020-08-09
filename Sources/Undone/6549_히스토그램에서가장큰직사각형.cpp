#include <iostream>
#include <vector>
#include <utility>
using namespace std;

const int INF = 2100000000;
typedef pair<int, int> P;

struct SegTree
{
	int n; //배열의 길이
	vector<P> rangeAns; //구간의 {높이 최소값, 해당 인덱스} 저장

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
			return rangeAns[node] = {arr[left], left};

		int mid = (left + right)/2;
		//좌측, 우측의 최소 높이를 구한다.
		P leftAns = Init(arr, left, mid, node*2);
		leftAns.second = max(leftAns.second, (mid-left+1)*leftAns.first);
		P rightAns = Init(arr, mid+1, right, node*2+1);
		rightAns.second = max(rightAns.second, (right-(mid+1)+1)*rightAns.first);

		if(leftAns.first >= rightAns.first)
		    return rangeAns[node]=rightAns;
		else if(leftAns.first < rightAns.first)
		    return rangeAns[node]=leftAns;
  }
    
    P Query(int left, int right, int node, int nodeLeft, int nodeRight)
    {
        if(right<nodeLeft || left>nodeRight)
            return {INF, 0};
        if(left<=nodeLeft == nodeRight)
            return rangeAns[node];
        
        int mid = (nodeLeft+nodeRight)/2;
        
        P leftAns = Query(left, right, node*2, nodeLeft, mid);
        P rightAns = Query(left, right, node*2+1, mid+1, nodeRight);
        
        int leftVal = (mid-nodeLeft+1)*leftAns.first;
        int rightVal = (nodeRight-mid)*rightAns.first;
        
        
        if(leftAns.first == rightAns.first) 
            return {leftAns.first, leftVal+rightVal};
        else
            return {min(leftAns.first, rightAns.first), max(leftVal, rightVal)};
    }
    
    int Query(int left, int right)
    {
        return Query(left, right, 1, 0, n-1).second;
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

        cout<<st.Query(0, n-1)<<"\n";
	}

	return 0;
}
