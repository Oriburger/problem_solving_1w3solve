#include <iostream>
using namespace std;

int n, answer = 1;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	for(int i=1; i<=n; i++)
		answer = answer * i;
	
	cout<<answer<<'\n';
	
	return 0;
}
