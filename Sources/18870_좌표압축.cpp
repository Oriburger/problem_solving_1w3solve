#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin>>n;
	vector<int> x1(n), x2(n);
	map<int, int> x; 

	for(int i=0; i<n; i++)
	{
		cin>>x2[i];
		x1[i]=x2[i];
		x[x1[i]]=-1;
	}
	sort(x1.begin(), x1.end());
	
	int cnt=0;
	for(int i=0; i<n; i++)
	{
		if(x[x1[i]]==-1)
			x[x1[i]] = cnt++;
	}

	for(int i=0; i<n; i++)
		cout<<x[x2[i]]<<' ';

	return 0;
}
