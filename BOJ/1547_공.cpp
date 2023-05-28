#include <bits/stdc++.h>
using namespace std;

int m, x, y, ans = 1;

int main()
{
    cin>>m;
    
    for(int i=0; i<m; i++)
	{
        cin>>x>>y;
        if(x == ans) ans = y;
		else if(y == ans) ans = x;
    }
    cout<<ans<<'\n';
    return 0;
}
