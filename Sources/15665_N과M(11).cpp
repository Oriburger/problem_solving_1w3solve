#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
vector<int> arr, ans;
set<int> check1;
vector<bool> check2(10001, false);

void Answer(int toPick, int picked)
{	
	if(toPick == 0)
	{
		if(check1.count(picked)!=0) return;
		
		check1.insert(picked);
		
		for(auto p : ans)
			cout<<p<<' ';
		cout<<'\n';
		
		return;
	}
		
	for(int i=0; i<n; i++)
	{
		int next = picked*10+arr[i];
		
		ans.push_back(arr[i]);
		Answer(toPick-1, next);
		ans.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	arr.resize(n);
	for(int i=0; i<n; i++)
		cin>>arr[i];
	sort(arr.begin(), arr.end());
	
	Answer(m, 0);
	
	return 0;
}
