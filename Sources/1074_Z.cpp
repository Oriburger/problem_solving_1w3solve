#include <iostream>
#include <cmath>
using namespace std;

int n, r, c, cnt=0;

void Search(int y, int x, int len)
{
	if(len==2)
	{
		if(y==r && x==c) cout<<cnt<<'\n';
		else if(y==r && x+1==c) cout<<cnt+1<<'\n';
		else if(y+1==r && x==c) cout<<cnt+2<<'\n';
		else if(y+1==r && x+1==c) cout<<cnt+3<<'\n';
		
		cnt+=4;
		
		return;
	}
	
	Search(y, x, len/2);
	Search(y, x+len/2, len/2);
	Search(y+len/2, x, len/2);
	Search(y+len/2, x+len/2, len/2);
	
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin>>n>>r>>c;
	
	Search(0, 0, pow(2, n));
	
	return 0;
}
