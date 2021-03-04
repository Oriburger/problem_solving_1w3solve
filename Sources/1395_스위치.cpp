#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct SegTree
{
	int n;
	vector<int> rangeAns; //해당 구간에 켜져있는 스위치 수
	vector<bool> lazy; //해당 구간이 toggle을 해야하는가?
	SegTree(int k)
	{
		n = k;
		rangeAns.resize(n*4, 0);
		lazy.resize(n*4, false); 
	}

	int query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		propagate(node, nodeLeft, nodeRight); //Query 연산을 해주기 전에, 미리 Propagate!
		
		if(right < nodeLeft || left > nodeRight) return 0; //범위에 포함되지 않는다면
		if(left <= nodeLeft && nodeRight <= right) return rangeAns[node]; //포함된다면

		int mid = (nodeLeft + nodeRight) / 2;
		int leftVal = query(left, right, node*2, nodeLeft, mid);
		int rightVal = query(left, right, node*2+1, mid+1, nodeRight);

		return leftVal + rightVal;
	}

	int query(int left, int right)
	{
		return query(left, right, 1, 0, n-1);
	}

	int update_range(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		propagate(node, nodeLeft, nodeRight); //구간 갱신 이전에 미리 Propagate

		if(right < nodeLeft || nodeRight < left) return rangeAns[node]; //구간에 포함되지 않는다면

		if(left <= nodeLeft && nodeRight <= right) //구간에 포함이 된다면
		{
			//구간의 스위치들을 Toggle (= 켜진 스위치들의 개수를 다시 셈)
			rangeAns[node] = (nodeRight - nodeLeft + 1) - rangeAns[node]; 
			if(nodeLeft != nodeRight) //리프 노드가 아니라면, 자식노드의 lazy값을 갱신해준다.
			{
				lazy[node*2] = !lazy[node*2]; 
				lazy[node*2+1] = !lazy[node*2+1]; 
			}
			return rangeAns[node];
		}

		int mid = (nodeLeft + nodeRight) / 2;

		return rangeAns[node] = update_range(left, right, node*2, nodeLeft, mid)
								+ update_range(left, right, node*2+1, mid+1, nodeRight);
	}

	int update_range(int left, int right)
	{
		return update_range(left, right, 1, 0, n-1);
	}

	void propagate(int node, int nodeLeft, int nodeRight) 
	{
		if(!lazy[node]) return; //갱신할 필요가 없다면

		rangeAns[node] = (nodeRight - nodeLeft + 1) - rangeAns[node]; //값 갱신

		if(nodeLeft != nodeRight) //리프노드가 아니라면, 자식노드들의 lazy값 갱신
		{
			lazy[node*2] = !lazy[node*2];
			lazy[node*2+1] = !lazy[node*2+1]; 
		}
		lazy[node] = false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, m;

	cin>>n>>m;	
	SegTree tree(n); 

	for(int i=0; i<m; i++)
	{
		int a, b, c;

		cin>>a>>b>>c;

		if(a==0) tree.update_range(b-1, c-1);
		else cout<<tree.query(b-1, c-1)<<'\n';
	}

	return 0;
}
