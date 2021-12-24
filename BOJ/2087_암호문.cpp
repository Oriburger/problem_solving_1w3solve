#include <bits/stdc++.h>
using namespace std;

int n, k;
string ans;
vector<int> arr;
unordered_map<int, string> m;

void DFS(int curr, int sum, string t, const bool flag)
{
	if(curr == (!flag ? n/2 : n))
	{
		if(!flag)
		{
			if(m.count(sum)==0)
				m[sum]=t;
		}
		else
		{
			if(m.count(k-sum)!=0) ans = m[k-sum]+t;
		}
		return;
	}

	DFS(curr+1, sum, t+"0", flag);
	DFS(curr+1, sum+arr[curr], t+"1", flag);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin>>n;

	arr = vector<int>(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	
	cin>>k;

	DFS(0, 0, "", false);
	DFS(n/2, 0, "", true);

	cout<<ans<<'\n';	

	return 0;
}
