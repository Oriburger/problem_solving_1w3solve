#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> arr, result;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	
	arr = result = vector<int>(n+1, 0);
	for(int i=1; i<=n; i++)
		cin>>arr[i];
	
	for(int i=1; i<=n; i++)
	{
		int cnt = 0, pos;
		for(pos=1; pos<=n; pos++)
		{
			cnt += (result[pos]==0);
			if(cnt == arr[i]) break;
		}
		if(arr[i] == 0) pos = 0;
		while(result[pos+1]!=0) pos++;
		result[pos+1] = i;
	}
	
	
	for(int i=1; i<=n; i++)
		cout<<result[i]<<' ';
	
	return 0;
}

