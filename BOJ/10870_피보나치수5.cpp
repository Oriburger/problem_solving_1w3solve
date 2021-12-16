#include <iostream>
#include <vector>
using namespace std;

int n=0;
int cache[21]={0,1,1};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=3; i<=n; i++)
		cache[i]=cache[i-1]+cache[i-2];
	
	cout<<cache[n]<<'\n';
	
	return 0;
}
