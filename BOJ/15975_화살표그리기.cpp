#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct dot { int pos; int color; };

bool comp(const dot& a, const dot& b)
{
	if(a.color != b.color) 
		return a.color < b.color;
	return a.pos < b.pos;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	long long n, ans = 0;
	vector<dot> arr; 
	
	cin>>n;
	
	dot tmp; 
	for(int i=0; i<n; i++)
	{
		cin>>tmp.pos>>tmp.color;
		arr.push_back(tmp);
	}
	sort(arr.begin(), arr.end(), comp);
	
	
	for(int i=0; i<n; i++)
	{
		int color = arr[i].color;
		int dist = 1e9 + 1;
		
		if(i > 0 && arr[i-1].color == color)
			dist = min(dist, arr[i].pos - arr[i-1].pos);
		if(i < n-1 && color == arr[i+1].color)
			dist = min(dist, arr[i+1].pos - arr[i].pos);
			
		if(dist != 1e9 + 1) ans += (long long)dist;
	}
	cout<<ans<<'\n';
	
	return 0;
}
