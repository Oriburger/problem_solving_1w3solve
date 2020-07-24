#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, m, ans=0, minGap = 9999999, minPicked=0;
bool button[10], flag=0;
vector<int> arr;

void GetNum(int curr, int picked)
{
	if(curr>999999) return;
	if(picked>=7) return;
	
	if(picked!=0 && minGap > abs(n-curr))
	{
		flag = true;
		ans = curr;
		minGap = abs(n-curr);
		minPicked=picked;
	}

	for(int i=0; i<arr.size(); i++)
	{
		GetNum(curr + arr[i] * pow(10, picked), picked+1);	
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
	
	GetNum(0, 0);
	
	cout<<ans<<'\n';
	
	if(flag)
		cout<<min(abs(100-n), abs(ans-n)+minPicked)<<'\n';
	else
		cout<<abs(100-n)<<'\n';
	
	return 0;
}
