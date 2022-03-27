#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int, int> P;

int n;
vector<int> arr, ans;
vector<P> tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	ans = arr = vector<int>(n, -1);
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		
		while(!tmp.empty())
		{
			if(tmp.back().second >= arr[i]) break;

			ans[tmp.back().first] = arr[i];
			tmp.pop_back();
		}
		tmp.push_back({i, arr[i]});		
	}
		
	for(auto &p : ans)
		cout<<p<<' ';
	cout<<'\n';
	
	return 0;
}
