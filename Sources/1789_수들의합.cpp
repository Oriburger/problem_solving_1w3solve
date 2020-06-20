#include <iostream>
using namespace std;

long long i, s, sum;

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>s;
	
	for(i=1; i<s; i++)
	{
		sum+=i;
		if(sum>s)
			break;
	}
	
	cout<<i-1<<'\n';
	
	return 0;
}
