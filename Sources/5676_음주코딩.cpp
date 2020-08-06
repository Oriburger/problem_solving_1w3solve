#include <iostream>
#include <vector>
using namespace std;

const int INF = 2147000000;

struct SegTree
{
	int n; //배열의 길이
	vector<int> rangeAns; //구간의 음수 개수 저장, 0이 있다면 -1

	SegTree(const vector<int>& arr)
	{
		n = arr.size();
		//이진트리 표현 위해 사이즈는 넉넉히 x4
		rangeAns.resize(n*4); 
		Init(arr, 0, n-1, 1);
	}

	int Init(const vector<int>& arr, int left, int right, int node)
	{
		if(left == right) 
			return rangeAns[node] = (arr[left] <= 0 ? (arr[left] == 0 ? INF : 1) : 0);
		
		int mid = (left + right) / 2;
		int leftAns = Init(arr, left, mid, node*2);
		int rightAns = Init(arr, mid+1, right, node*2+1);

          //cout<<"{"<<left<<","<<right<<"} : "<<leftAns<<" "<<rightAns<<"\n";
		
		if(leftAns==INF || rightAns==INF)
			return rangeAns[node] = INF;
		else
		     return rangeAns[node] = leftAns + rightAns;
	}

	int Query(int left, int right, int node, int nodeLeft, int nodeRight)
	{
		if(right < nodeLeft || left > nodeRight) return 0;
		if(left <= nodeLeft && nodeRight <= right) return rangeAns[node];

		int mid = (nodeLeft + nodeRight)/2;
		
		int leftAns = Query(left, right, node*2, nodeLeft, mid);
		int rightAns = Query(left, right, node*2+1, mid+1, nodeRight);

        //  cout<<"{"<<left<<","<<right<<"} : "<<leftAns<<" "<<rightAns<<"\n";
		  
		if(leftAns==INF || rightAns==INF) return INF;
		
		else return leftAns + rightAns;
	}

	int Update(int idx, int newVal, int node, int nodeLeft, int nodeRight)
	{
		if(idx<nodeLeft || idx>nodeRight) return rangeAns[node];
		if(nodeLeft == nodeRight) 
			return rangeAns[node] = newVal <=0 ? (newVal == 0 ? INF : 1) : 0;
		
		int mid = (nodeLeft + nodeRight) / 2;
		
		int leftAns = Update(idx, newVal, node*2, nodeLeft, mid);
		int rightAns = Update(idx, newVal, node*2+1, mid+1, nodeRight);

		if(leftAns==INF || rightAns==INF) return rangeAns[node]=INF;
		
		else return rangeAns[node] = leftAns + rightAns;
	}

	int Query(int left, int right)
	{
		return Query(left, right, 1, 0, n-1);
	}

	int Update(int idx, int newVal)
	{
		return Update(idx, newVal, 1, 0, n-1);
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(1)
	//for(int a=0; a<2; a++)
	{
		int n, k;
		vector<int> arr;


        //cin>>n>>k;
		if(!(cin>>n>>k)) break;

		arr.resize(n);
		for(int i=0; i<n; i++)
			cin>>arr[i];
		
		SegTree st(arr);
		
		for(int i=0; i<k; i++)
		{
			char cmd; int a, b;
			cin>>cmd;
			cin>>a>>b;

			if(cmd == 'C')
			{
				st.Update(a-1, b);
			}
			else if(cmd == 'P')
			{
				int next = st.Query(a-1, b-1);
			//	cout<<"next : "<<next<<"\n";
				if(next%2==1)
					cout<<'-';
				else if(next==INF)
					cout<<0;
				else if(next%2==0)
					cout<<'+';
			}
			
		//	cout<<"\n";
		}
		cout<<'\n';
	}

	return 0;
}
