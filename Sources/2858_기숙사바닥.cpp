#include <iostream>
using namespace std;

int r, b, l, w;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>r>>b;
	
	int w=0;
	for(l=1; l<=r+b; l++)
	{
		if((r+b)%l != 0) continue;
		
		w=(r+b)/l;
		
		if((w-2)*(l-2) == b) break;
	}
	
	if(w>l) cout<<w<<' '<<l<<'\n';
	else cout<<l<<' '<<w<<'\n';
		
	return 0;
}
