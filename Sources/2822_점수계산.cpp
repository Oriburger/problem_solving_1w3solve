#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int, int> > arr;
vector<int> ans;
int sum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int i=0; i<8; i++)
	{
		int input;
		cin>>input;
		
		arr.push_back({input, i+1});
	}
	
	sort(arr.begin(), arr.end(), greater<pair<int, int> >());
	
	for(int i=0; i<5; i++)
	{
		sum+=arr[i].first;
		ans.push_back(arr[i].second);
	}
	
	cout<<sum<<'\n';
	
	sort(ans.begin(), ans.end());
	for(int i=0; i<5; i++)
		cout<<ans[i]<<' ';
	
	return 0;
}
