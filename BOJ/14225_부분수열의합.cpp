#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans; 
vector<int> arr;
vector<bool> result;

void getResult(int idx, int sum)
{	
	result[sum] = true;
	if(idx == n) return;
	
	getResult(idx+1, sum + arr[idx]);
	getResult(idx+1, sum);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	arr = vector<int>(n);
	
	int tmp = 0;
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		tmp += arr[i];
	}
	result = vector<bool>(tmp+1, false);
	
	getResult(0, 0);
	
	for(int i=1; i<=tmp+1; i++)
		if(!result[i])
		{
			ans = i;
			break;
		}
	cout<<ans<<'\n';
	
	
	return 0;
}
