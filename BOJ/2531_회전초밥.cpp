#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, d, k, c;
int lo, hi, sum, ans;
vector<int> sushi, st, check;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>d>>k>>c;
	
	sushi = vector<int>(n);
	check = vector<int>(d+1, 0);
	for(int i=0; i<n; i++)
		cin>>sushi[i];
	
	
	for(int i=0; i<k; i++)
	{
		if(!check[sushi[hi]]) sum += 1;
		check[sushi[hi]] += 1;
		if(i<k-1) hi = (hi+1)%n;
	}
	ans = sum + (check[c]==0);
	
	for(int i=0; i<n; i++)
	{
		check[sushi[lo]]-=1;
		if(!check[sushi[lo]]) sum -= 1;
		lo = (lo+1)%n;
		
		hi = (hi+1)%n;
		if(check[sushi[hi]]==0) sum += 1;
		check[sushi[hi]]+=1;
		
		ans = max(sum + (check[c]==0), ans);
		if(ans == k+1) break;
	}
	cout<<ans<<'\n';
	
	return 0;
}
