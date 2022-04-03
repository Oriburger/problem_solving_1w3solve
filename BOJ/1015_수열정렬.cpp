#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n; 
vector<int> a, tmp;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n;
	
	a = tmp = vector<int>(n);
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		a[i] = a[i]*100+i;
	}
	
	tmp = a;
	sort(a.begin(), a.end());
	
	for(auto &k : tmp)
		cout<<lower_bound(a.begin(), a.end(), k) - a.begin()<<' ';
	
	return 0;
}
