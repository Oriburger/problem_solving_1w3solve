#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int n, m;
vector<int> arr, ans;
set<int> check1;
vector<bool> check2(10001, false);

void Answer(int toPick, int picked, int lastPick)
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
		if(lastPick>i) continue;
		if(check2[i]) continue;
		
		int next = picked*10+arr[i];
		
		ans.push_back(arr[i]);
		check2[i]=true;
		
		Answer(toPick-1, next, i);
	
		check2[i]=false;
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
	
	Answer(m, 0, 0);
	
	return 0;
}
