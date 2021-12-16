#include <iostream>
#include <vector>
using namespace std;

int n;
int r, e, c;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	while(n--)
	{
		cin>>r>>e>>c;
		
		if(r < e-c)
			cout<<"advertise\n";
		else if(r == e-c)
			cout<<"does not matter\n";
		else
			cout<<"do not advertise\n";
	}
	
	return 0;
}
