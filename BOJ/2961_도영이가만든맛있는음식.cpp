#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Veg { int s; int b; };

int n, ans; 
vector<Veg> arr; 

int getAnswer(int idx, int s, int b)
{
	if(idx == n) return 1e9;
	
	int ret = getAnswer(idx+1, s, b);
	
	s = s == 0 ? 1 : s;
	s *= arr[idx].s;
	b += arr[idx].b;
	ret = min(ret, abs(s-b));
	
	ret = min(ret, getAnswer(idx+1, s, b));
	
	return ret;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n; 
	arr = vector<Veg>(n);
	
	for(int i=0; i<n; i++)
		cin>>arr[i].s>>arr[i].b;
		
	ans = getAnswer(0, 0, 0);

	cout<<ans<<'\n';
	
	return 0;
}
