#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, q, ans=0;
	vector<int> a, b, s;
	
	cin>>n>>q;
	
	a.resize(n, 0);
	b.resize(n, 0);
	s.resize(n, 0);
	for(int i=0; i<n; i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b.begin(), b.end());
	
	s[0]=b[0];
	for(int i=1; i<n; i++)
		s[i]=s[i-1]+b[i];
	
	while(q--)
	{
		int l, r;
		
		cin>>l>>r;
		
		if(l>1)
			cout<<s[r-1]-s[l-2]<<'\n';
		else
			cout<<s[r-1]<<'\n';
	}
	
	return 0;
}
