//리모컨 새로 사라고

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int n, m, ans=0, minGap = 9999999, minPicked=999999;
bool button[10], flag=0;
vector<int> arr, seq;

void GetNum(int curr)
{
	if(seq.size()==7) return;
	
	if(seq.size()!=0 && minGap >= abs(n-curr))
	{
		flag = true;
		ans = curr;
	
		if(minGap == abs(n-curr))
			minPicked = min(minPicked, (int)seq.size());
		else minPicked = (int)seq.size();
		
		minGap = abs(n-curr);
			
	//	cout<<ans<<','<<minGap<<','<<minPicked<<'\n';
	}
	
	if(seq.size()==1 && seq[0]==0) return;
	
	for(int i=0; i<arr.size(); i++)
	{
		seq.push_back(arr[i]);
		GetNum(curr * 10 + arr[i]);
		seq.pop_back();
	}
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>m;
	
	for(int i=0; i<m; i++)
	{
		int input;
		cin>>input;
		button[input]=true;
	} 
	
	for(int i=0; i<=9; i++)
		if(!button[i]) arr.push_back(i);
	
	GetNum(0);
	
	if(flag)
		cout<<min(abs(100-n), abs(ans-n)+minPicked)<<'\n';
	else
		cout<<abs(100-n)<<'\n';
	
	return 0;
}
