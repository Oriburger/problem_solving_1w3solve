#include <bits/stdc++.h>
#define INF 1e9+7;
using namespace std;

int n, ans;
vector<int> w;

int getAnswer(vector<int> arr, int total)
{
	if(arr.size()<=2) 
	{
		ans = max(ans, total);
		return ans;
	}

	for(int i=1; i<arr.size()-1; i++)
	{
		int temp = arr[i];
		arr.erase(arr.begin()+i);
		getAnswer(arr, total + arr[i-1] * arr[i]);
		arr.insert(arr.begin()+i, temp);
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin>>n;

	w = vector<int>(n, 0);
	for(int i=0; i<n; i++)
	{
		cin>>w[i];
	}

	cout<<getAnswer(w, 0)<<'\n';	
	
	return 0;
}
