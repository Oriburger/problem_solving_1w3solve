#include <iostream>
using namespace std;

int n, l, x=-1, t, pos;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>l;
	
	for(int i=l; i<=100; i++)
	{
		t = (i-1)*i / 2;
		if((n-t)%i==0 && (n-t)/i>=0)
		{
			x=(n-t)/i;
			pos = i;
			break;
		}
	}
	
	if(x==-1) cout<<x<<'\n';
	else
		for(int i=0; i<pos; i++)
			cout<<x+i<<' ';
	
	return 0;
}
